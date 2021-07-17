// #include <stdlib.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// typedef struct Node {
//     int key;
//     struct Node *left, *right;
// }Node;
// Node *createNode (int value) {
//     Node *newNode = (Node *)malloc (sizeof (Node));
//     newNode->key = value;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }
// typedef struct DLinkedList {
//     int key; 
//     struct DLinkedList *prev, *next;
// }DLinkedList;
// DLinkedList *createDLinkedList(int value){
//     DLinkedList *newDLinkedList = (DLinkedList *)malloc (sizeof (DLinkedList));
//     newDLinkedList->key = value;
//     newDLinkedList->prev = NULL;
//     newDLinkedList->next = NULL;
//     return newDLinkedList;
// } 
// void VSumUtility (Node *root, DLinkedList *sumNode)
// {
//     sumNode->key = sumNode->key + root->key;
//     if (root->left)
//     {
//         if (sumNode->prev == NULL){
//             sumNode->prev = createDLinkedList(0);
//             sumNode->prev->next = sumNode;
//         }
//         VSumUtility(root->left,sumNode->prev);
//     }
//     if (root->right)
//     {
//         if (sumNode->next == NULL){
//             sumNode->next = createDLinkedList(0);
//             sumNode->next->prev = sumNode;
//         }
//         VSumUtility(root->right, sumNode->next);
//     }
// }
// void VSum (Node *root)
// {
//     DLinkedList *sumNode = createDlinkedList(0);
//     VSumUtility(root, sumNode);
//     while (sumNode->prev != NULL)
//     {
//         sumNode = sumNode->prev;
//     }
//     while (sumNode != NULL){
//         printf("%d ", sumNode->key);
//         sumNode = sumNode->next;
//     }
// }
// int main()
// {
//     Node *node;
//     int n;
//     scanf ("%d", &n);
//     int x;
//     char pilih[10001];
//     for (int i=0; i<n; i++)
//     {
//         scanf("%s", pilih);
//         if (strcmp(pilih, "insert") == 0)
//         {
//             scanf("%d", &x);
//             createNode(x);
//         }
//         if (strcmp(pilih, "print") == 0)
//         {
//             VSum(node);
//         }
//     }
//     return 0;
// }



























// #include <stdlib.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// // HashMap
// typedef struct HashMapNode{
//     unsigned int hash_index;
//     int value;
// }HashMapNode;

// typedef struct HashMap{
//     int element_count;
//     int map_size;
//     HashMapNode ** node_list;
// }HashMap;

// // AVL Node 
// typedef struct AVLNode_t
// {
//     int data;
//     struct AVLNode_t *left,*right;
//     int height;
// }AVLNode;

// typedef struct AVL_t
// {
//     AVLNode *_root;
//     unsigned int _size;
// }AVL;

// // Linked List 


// AVLNode* _avl_createNode(int value) {
//     AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
//     newNode->data = value;
//     newNode->height=1;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }
// // Doubly Linked List 
// struct DLLNode {
//     int data;
//     struct DLLNode *prev, *next;
// };
// AVLNode* _search(AVLNode *root, int value) {
//     while (root != NULL) {
//         if (value < root->data)
//             root = root->left;
//         else if (value > root->data)
//             root = root->right;
//         else
//             return root;
//     }
//     return root;
// }

// int _getHeight(AVLNode* node){
//     if(node==NULL)
//         return 0; 
//     return node->height;
// }

// int _max(int a,int b){
//     return (a > b)? a : b;
// }

// AVLNode* _rightRotate(AVLNode* pivotNode) {

//     AVLNode* newParrent=pivotNode->left;
//     pivotNode->left=newParrent->right;
//     newParrent->right=pivotNode;

//     pivotNode->height=_max(_getHeight(pivotNode->left),
//                       _getHeight(pivotNode->right))+1;
//     newParrent->height=_max(_getHeight(newParrent->left),
//                        _getHeight(newParrent->right))+1;
    
//     return newParrent;
// }

// AVLNode* _leftRotate(AVLNode* pivotNode) {

//     AVLNode* newParrent=pivotNode->right;
//     pivotNode->right=newParrent->left;
//     newParrent->left=pivotNode;

//     pivotNode->height=_max(_getHeight(pivotNode->left),
//                       _getHeight(pivotNode->right))+1;
//     newParrent->height=_max(_getHeight(newParrent->left),
//                        _getHeight(newParrent->right))+1;
    
//     return newParrent;
// }

// AVLNode* _leftCaseRotate(AVLNode* node){
//     return _rightRotate(node);
// }

// AVLNode* _rightCaseRotate(AVLNode* node){
//     return _leftRotate(node);
// }

// AVLNode* _leftRightCaseRotate(AVLNode* node){
//     node->left=_leftRotate(node->left);
//     return _rightRotate(node);
// }

// AVLNode* _rightLeftCaseRotate(AVLNode* node){
//     node->right=_rightRotate(node->right);
//     return _leftRotate(node);
// }

// int _getBalanceFactor(AVLNode* node){
//     if(node==NULL)
//         return 0;
//     return _getHeight(node->left)-_getHeight(node->right);
// }

// AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value) {
    
//     if(node==NULL) // udah mencapai leaf
//         return _avl_createNode(value);
//     if(value < node->data)
//         node->left = _insert_AVL(avl,node->left,value);
//     else if(value > node->data)
//     	node->right = _insert_AVL(avl,node->right,value);
    
//     node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

//     int balanceFactor=_getBalanceFactor(node);
    
//     if(balanceFactor > 1 && value < node->left->data) // skewed kiri (left-left case)
//         return _leftCaseRotate(node);
//     if(balanceFactor > 1 && value > node->left->data) // 
// 		return _leftRightCaseRotate(node);
//     if(balanceFactor < -1 && value > node->right->data)
//         return _rightCaseRotate(node);
//     if(balanceFactor < -1 && value < node->right->data)
//         return _rightLeftCaseRotate(node);
    
//     return node;
// }

// AVLNode* _findMinNode(AVLNode *node) {
//     AVLNode *currNode = node;
//     while (currNode && currNode->left != NULL)
//         currNode = currNode->left;
//     return currNode;
// }

// AVLNode* _remove_AVL(AVLNode* node,int value){
//     if(node==NULL)
//         return node;
//     if(value > node->data)
//     	node->right=_remove_AVL(node->right,value);
//     else if(value < node->data)
//     	node->left=_remove_AVL(node->left,value);
//     else{
//         AVLNode *temp;
//         if((node->left==NULL)||(node->right==NULL)){
//             temp=NULL;
//             if(node->left==NULL) temp=node->right;  
//             else if(node->right==NULL) temp=node->left;
            
//             if(temp==NULL){
//                 temp=node;
//                 node=NULL;
//             }
//             else
//                 *node=*temp;   
            
//             free(temp);
//         }
//         else{
//             temp = _findMinNode(node->right);
//             node->data=temp->data;
//             node->right=_remove_AVL(node->right,temp->data);
//         }    
//     }

// 	if(node==NULL) return node;
    
//     node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

//     int balanceFactor= _getBalanceFactor(node);
    
//     if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
//         return _leftCaseRotate(node);

//     if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
//         return _leftRightCaseRotate(node);
  
//     if(balanceFactor < -1 && _getBalanceFactor(node->right)<=0) 
//         return _rightCaseRotate(node);

//     if(balanceFactor < -1 && _getBalanceFactor(node->right)>0) 
//         return _rightLeftCaseRotate(node);
    
//     return node;
// }

// void avl_init(AVL *avl) {
//     avl->_root = NULL;
//     avl->_size = 0u;
// }

// bool avl_isEmpty(AVL *avl) {
//     return avl->_root == NULL;
// }

// bool avl_find(AVL *avl, int value) {
//     AVLNode *temp = _search(avl->_root, value);
//     if (temp == NULL)
//         return false;
    
//     if (temp->data == value)
//         return true;
//     else
//         return false;
// }

// void avl_insert(AVL *avl,int value){
//     if(!avl_find(avl,value)){
//         avl->_root=_insert_AVL(avl,avl->_root,value);
//         avl->_size++;
//     }

// }

// void avl_remove(AVL *avl,int value){
//     if(avl_find(avl,value)){
//         avl->_root=_remove_AVL(avl->_root,value);
//         avl->_size--;
//     }
// }


// HashMapNode *hashmap_new_node(unsigned int hash_index, int values_size){
//     HashMapNode *hashmap_node = malloc(sizeof(HashMapNode));
//     hashmap_node->hash_index = hash_index;
//     hashmap_node->value = values_size;
//     hashmap_node->value = malloc(sizeof(values_size * sizeof(int))); 

//     return hashmap_node;
// }


// void JumlahKolom (AVLNode *node, int hd){
//     if (node == NULL){
//         return;
//     }
//     JumlahKolom(node->left, hd - 1);
//     // int array[] = 0;
//     // array[hd] += node->data;
//     JumlahKolom(node->right, hd + 1);
// }

// int main(){
//     AVL avlku, *avl;
//     avl_init(&avlku);
//     int n;
//     scanf("%d", &n);
//     int x;
//     char *pilih;
//     for (int i=0; i<n; i++){
//         scanf("%s", pilih);
//         if (strcmp(pilih,"insert") == 0){
//             scanf("%d", &x);
//             avl_insert(&avlku, x);
//         }
//         if (strcmp(pilih,"remove") == 0){
//             scanf("%d", &x);
//             avl_remove(&avlku, x);
//         }
//         if (strcmp(pilih,"print") == 0){
//             int jarakVertikal = 0;
//             JumlahKolom(avl->_root, jarakVertikal);
//         } 
//     }
//     for (int i = 0; i < n; i++){

//     }
//     return 0;
// }



// // //  [IMPLEMENTASI HASHMAP IN C]
// // // https://codereview.stackexchange.com/questions/141493/hash-map-implementation 






#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct AVLNode_t
{
    int data;
    int height;
    struct AVLNode_t *left,*right;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
}AVL;

typedef struct dnode_t 
{
    int data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

/* Struktur ADT List */

typedef struct dlist_t 
{
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} List;

AVLNode* _avl_createNode(int value) 
{
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height=1;

    newNode->left = newNode->right = NULL;

    return newNode;
}

AVLNode* _search(AVLNode *root, int value) 
{
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
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

AVLNode* _insert_AVL(AVL *avl,AVLNode *node,int value) 
{
    
    if(node==NULL) // udah mencapai leaf
        return _avl_createNode(value);
    if(value < node->data)
        node->left = _insert_AVL(avl,node->left,value);
    else if(value > node->data)
     node->right = _insert_AVL(avl,node->right,value);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

    int balanceFactor=_getBalanceFactor(node);
    
    if(balanceFactor > 1 && value < node->left->data) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && value > node->left->data) // 
  return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && value < node->right->data)
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

bool avl_find(AVL *avl, int value) 
{
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl,int value)
{
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value);
    }
}

DListNode* __dlist_createNode(int value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void dlist_init(List *list)
{
    list->_head = list->_tail = NULL;
    list->_size = (unsigned) 0;
}

void JumlahAngka(AVLNode *node, DListNode *tempNode)
{
    tempNode->data = tempNode->data + node->data;
 
    if(node->left)
    {
        if(tempNode->prev == NULL)
        {
            tempNode->prev = __dlist_createNode(0);
            tempNode->prev->next = tempNode;
        }
        JumlahAngka(node->left, tempNode->prev);
    }
 
    if(node->right)
    {
        if(tempNode->next == NULL)
        {
            tempNode->next = __dlist_createNode(0);
            tempNode->next->prev = tempNode;
        }
        JumlahAngka(node->right, tempNode->next);
    }
}
 
void PrintAngka(AVLNode* node)
{
    List dlist;
    dlist_init(&dlist);

    DListNode* tempNode = __dlist_createNode(0);
    JumlahAngka(node, tempNode);
 
    while(tempNode->prev != NULL) //dimulai dari kolom belakang
    {
        tempNode = tempNode->prev;
    }
 
    while(tempNode != NULL)
    {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
}

int main()
{
    AVL avlku;
    avl_init(&avlku);

    int N;
    int angka;

    scanf("%d",&N);

    char kata1[] = "insert";
    char kata2[] = "print";
    char pil[8];

    for(int i = 0; i < N; i++)
    {
        scanf("%s",pil);
        
        if(strcmp(pil,kata1) == 0)
        {
            scanf("%d",&angka);
            avl_insert(&avlku,angka);
        }
        else if(strcmp(pil,kata2) == 0)
        {
            PrintAngka(avlku._root);
            printf("\n");
        }
    }
}