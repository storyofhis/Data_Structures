#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef struct AVLNode_t
{
    int data;
    int id;
    int height;
 
    struct AVLNode_t *left,*right;
}AVLNode;
 
typedef struct AVL_t
{
    AVLNode *_root;
}AVL;
 
AVLNode* _avl_createNode(int value,int index) 
{
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->id = index;
    newNode->height=1;
 
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
int _getHeight(AVLNode* node)
{
    if(node==NULL)
        return 0; 
    return node->height;
}
 
int _max(int a,int b)
{
    return (a > b)? a : b;
}
AVLNode* _rightRotate(AVLNode* pivotNode) 
{
 
    AVLNode* newParrent=pivotNode->left;
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;
 
    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
 
    return newParrent;
}
 
AVLNode* _leftRotate(AVLNode* pivotNode) 
{
 
    AVLNode* newParrent=pivotNode->right;
    pivotNode->right=newParrent->left;
    newParrent->left=pivotNode;
 
    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
 
    return newParrent;
}
 
AVLNode* _leftCaseRotate(AVLNode* node)
{
    return _rightRotate(node);
}
 
AVLNode* _rightCaseRotate(AVLNode* node)
{
    return _leftRotate(node);
}
 
AVLNode* _leftRightCaseRotate(AVLNode* node)
{
    node->left=_leftRotate(node->left);
    return _rightRotate(node);
}
 
AVLNode* _rightLeftCaseRotate(AVLNode* node)
{
    node->right=_rightRotate(node->right);
    return _leftRotate(node);
}
 
int _getBalanceFactor(AVLNode* node)
{
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}
 
AVLNode* _search(AVLNode *root, int index) 
{
    while (root != NULL) 
    {
        if (index < root->id)
            root = root->left;
        else if (index > root->id)
            root = root->right;
        else
            return root;
    }
    return root;
}
 
AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value,int index) 
{
 
    if(node==NULL) // udah mencapai leaf
        return _avl_createNode(value,index);
    if(index < node->id)
        node->left = _insert_AVL(avl,node->left,value,index);
    else if(index > node->id)
        node->right = _insert_AVL(avl,node->right,value,index);
 
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 
 
    int balanceFactor=_getBalanceFactor(node);
 
    if(balanceFactor > 1 && index < node->left->id) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && index > node->left->id) // 
        return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && index > node->right->id)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && index < node->right->id)
        return _rightLeftCaseRotate(node);
    return node;
}
 
void avl_init(AVL *avl) 
{
    avl->_root = NULL;
}
 
bool avl_isEmpty(AVL *avl) 
{
    return avl->_root == NULL;
}
 
bool avl_find(AVL *avl, int index) 
{
    AVLNode *temp = _search(avl->_root, index);
    if (temp == NULL)
        return false;
 
    if (temp->id == index)
        return true;
    else
        return false;
}
 
void avl_insert(AVL *avl,int value,int index)
{
    if(!avl_find(avl,index))
    {
        avl->_root=_insert_AVL(avl,avl->_root,value,index);
    }
}
 
int MencariNafkah(AVL *avl, int index, int BanyakBarang)
{
    AVLNode *temp = _search(avl->_root, index);
 
    return (BanyakBarang*temp->data);
}
 
int main()
{
    AVL avlku;
    avl_init(&avlku);
 
    int M,N,X,Y;
    int Total = 0;
 
    scanf("%d %d",&M,&N);
 
    int CheckID = M; //digunakan untuk mengecek apakah id urut tidak
    int Berhenti = 0; //mengecek apakah program berhenti
 
    while(M != 0 && N != 0)
    {
        avl_insert(&avlku,N,M);
 
        scanf("%d %d",&M,&N);
        if(M - CheckID == 1)
        {
            CheckID = M;
            continue;
        }
        else if(M != 0 && N != 0 && (M - CheckID != 0))
        {
            printf("ID harus urut\n");
            Berhenti = 1;
            break;
        } 
    }
 
    if(Berhenti != 1)
    {
        scanf("%d %d",&X,&Y);
 
        while(X != 0 && Y != 0)
        {
            if(avl_find(&avlku,Y))
            {
                int hasil = MencariNafkah(&avlku,Y,X);
                Total += hasil;
            }
            else
                printf("Maaf barang tidak tersedia\n");
 
            scanf("%d %d",&X,&Y);
        }
 
        printf("%d",Total);
    }
}




// #include <stdlib.h>
// #include <stdbool.h>
// #include <stdio.h>
 
// typedef struct AVLNode_t
// {
//     int data;
//     int id;
//     int height;
 
//     struct AVLNode_t *left,*right;
// }AVLNode;
 
// typedef struct AVL_t
// {
//     AVLNode *_root;
// }AVL;
 
// AVLNode* _avl_createNode(int value,int index) 
// {
//     AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
//     newNode->data = value;
//     newNode->id = index;
//     newNode->height=1;
 
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }
 
// int _getHeight(AVLNode* node)
// {
//     if(node==NULL)
//         return 0; 
//     return node->height;
// }
 
// int _max(int a,int b)
// {
//     return (a > b)? a : b;
// }
// AVLNode* _rightRotate(AVLNode* pivotNode) 
// {
 
//     AVLNode* newParrent=pivotNode->left;
//     pivotNode->left=newParrent->right;
//     newParrent->right=pivotNode;
 
//     pivotNode->height=_max(_getHeight(pivotNode->left),
//                       _getHeight(pivotNode->right))+1;
//     newParrent->height=_max(_getHeight(newParrent->left),
//                        _getHeight(newParrent->right))+1;
 
//     return newParrent;
// }
 
// AVLNode* _leftRotate(AVLNode* pivotNode) 
// {
 
//     AVLNode* newParrent=pivotNode->right;
//     pivotNode->right=newParrent->left;
//     newParrent->left=pivotNode;
 
//     pivotNode->height=_max(_getHeight(pivotNode->left),
//                       _getHeight(pivotNode->right))+1;
//     newParrent->height=_max(_getHeight(newParrent->left),
//                        _getHeight(newParrent->right))+1;
 
//     return newParrent;
// }
 
// AVLNode* _leftCaseRotate(AVLNode* node)
// {
//     return _rightRotate(node);
// }
 
// AVLNode* _rightCaseRotate(AVLNode* node)
// {
//     return _leftRotate(node);
// }
 
// AVLNode* _leftRightCaseRotate(AVLNode* node)
// {
//     node->left=_leftRotate(node->left);
//     return _rightRotate(node);
// }
 
// AVLNode* _rightLeftCaseRotate(AVLNode* node)
// {
//     node->right=_rightRotate(node->right);
//     return _leftRotate(node);
// }
 
// int _getBalanceFactor(AVLNode* node)
// {
//     if(node==NULL)
//         return 0;
//     return _getHeight(node->left)-_getHeight(node->right);
// }
 
// AVLNode* _search(AVLNode *root, int index) 
// {
//     while (root != NULL) 
//     {
//         if (index < root->id)
//             root = root->left;
//         else if (index > root->id)
//             root = root->right;
//         else
//             return root;
//     }
//     return root;
// }
 
// AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value,int index) 
// {
 
//     if(node==NULL) // udah mencapai leaf
//         return _avl_createNode(value,index);
//     if(index < node->id)
//         node->left = _insert_AVL(avl,node->left,value,index);
//     else if(index > node->id)
//         node->right = _insert_AVL(avl,node->right,value,index);
 
//     node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 
 
//     int balanceFactor=_getBalanceFactor(node);
 
//     if(balanceFactor > 1 && index < node->left->id) // skewed kiri (left-left case)
//         return _leftCaseRotate(node);
//     if(balanceFactor > 1 && index > node->left->id) // 
//         return _leftRightCaseRotate(node);
//     if(balanceFactor < -1 && index > node->right->id)
//         return _rightCaseRotate(node);
//     if(balanceFactor < -1 && index < node->right->id)
//         return _rightLeftCaseRotate(node);
//     return node;
// }
 
// void avl_init(AVL *avl) 
// {
//     avl->_root = NULL;
// }
 
// bool avl_isEmpty(AVL *avl) 
// {
//     return avl->_root == NULL;
// }
 
// bool avl_find(AVL *avl, int index) 
// {
//     AVLNode *temp = _search(avl->_root, index);
//     if (temp == NULL)
//         return false;
 
//     if (temp->id == index)
//         return true;
//     else
//         return false;
// }
 
// void avl_insert(AVL *avl,int value,int index)
// {
//     if(!avl_find(avl,index))
//     {
//         avl->_root=_insert_AVL(avl,avl->_root,value,index);
//     }
// }
 
// int MencariNafkah(AVL *avl, int index, int BanyakBarang)
// {
//     AVLNode *temp = _search(avl->_root, index);
 
//     return (BanyakBarang*temp->data);
// }
 
// int main()
// {
//     AVL avlku;
//     avl_init(&avlku);
 
//     int M,N,X,Y;
//     int Total = 0;
 
//     scanf("%d %d",&M,&N);
 
//     int CheckID = M; //digunakan untuk mengecek apakah id urut tidak
//     int Berhenti = 0; //mengecek apakah program berhenti
 
//     while(M != 0 && N != 0)
//     {
//         avl_insert(&avlku,N,M);
 
//         scanf("%d %d",&M,&N);
//         if(M - CheckID == 1)
//         {
//             CheckID = M;
//             continue;
//         }
//         else if(M != 0 && N != 0 && (M - CheckID != 0))
//         {
//             printf("ID harus urut");
//             Berhenti = 1;
//             break;
//         } 
//     }
 
//     if(Berhenti != 1)
//     {
//         scanf("%d %d",&X,&Y);
 
//         while(X != 0 && Y != 0)
//         {
//             if(avl_find(&avlku,Y))
//             {
//                 int hasil = MencariNafkah(&avlku,Y,X);
//                 Total += hasil;
//             }
//             else
//                 printf("Maaf barang tidak tersedia\n");
 
//             scanf("%d %d",&X,&Y);
//         }
 
//         printf("%d",Total);
//     }
// }