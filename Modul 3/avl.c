// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// typedef struct AVLNode {
//     int data;
//     struct AVLNode *left;
//     struct AVLNode *right;
//     int height;
// }AVLNode;
// typedef struct AVL{
//     AVLNode *_root;
//     unsigned int size;
// }AVL;
// // Membuat node baru
// AVLNode *createNode (int value){
//     AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
//     newNode->data = value;
//     newNode->height = 1;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }
// // mencari node dengan nilai tertentu 
// AVLNode *search(AVLNode *root, int value){
//     while(root != NULL){
//         if (value < root->data){
//             root = root->left;
//         }else if (value > root->data){
//             root = root->right;
//         }else {
//             return root;
//         }
//     }
//     return root;
// }
// int getHeight (AVLNode *node){
//     if (node == NULL)
//         return 0;
//     return node->height;
// }
// int max(int a, int b){
//     return (a > b)? a : b;
// }
// int getBalanceFactor(AVLNode *node){
//     if (node == NULL){
//         return 0;
//     }return getHeight(node->left) - getHeight(node->right);
// }

// // ROTASI!

// // rotasi Kanan 
// AVLNode *rightrotate(AVLNode *pivotNode){
//     AVLNode *newParent = pivotNode->left;
//     pivotNode->left = newParent->right;
//     newParent->right = pivotNode;

//     pivotNode->height = max(getHeight(pivotNode->left), getHeight(pivotNode->right))+1;
//     newParent->height = max(getHeight(pivotNode->left), getHeight(pivotNode->right))+1;
//     return newParent;
// }
// AVLNode *rightCaseRotate(AVLNode *node){
//     return rightrotate(node);
// }
// // Rotasi Kiri
// AVLNode *leftrotate(AVLNode *pivotNode){
//     AVLNode *newParent = pivotNode->right;
//     pivotNode->right = newParent->left;
//     newParent->left = pivotNode;

//     pivotNode->height = max(getHeight(pivotNode->left), getHeight(pivotNode->right))+1;
//     newParent->height = max(getHeight(pivotNode->left), getHeight(pivotNode->right))+1;

//     return newParent;
// }
// AVLNode *leftCaseRotate(AVLNode *node){
//     return leftrotate(node);
// }


// // (Left-Right zig-zag)
// AVLNode *leftRightZigzag(AVLNode *node){
//     node->left = leftrotate(node->left);
//     return rightrotate(node);
// }

// // (Right-Left zig-zag)
// AVLNode *rightLeftZigzag(AVLNode *node){
//     node->right = rightrotate(node->right);
//     return leftrotate(node);
// }

// AVLNode *insert(AVL *avl, AVLNode *node, int value){
//     // udah mencapai leaf
//     if (node == NULL)
//         return createNode(value);
//     if (value < node->data)
//         node->left = insert(avl, node->left, value);
//     else if (value > node->data)
//         node->right = insert(avl, node->right, value);
    
//     node->height = 1 + max(getHeight(node->left), getHeight(node->right));

//     int balanceFactor = getBalanceFactor(node);

//     if (balanceFactor > 1 && value < node->left->data)  // skewed kiri (left-left case)
//         return leftCaseRotate(node);
//     if (balanceFactor > 1 && value > node->left->data)  // skewed kiri (left-right case)
//         return leftRightZigzag(node);
//     if (balanceFactor < -1 && value > node->right->data) // skewed kanan (right-right case)
//         return rightCaseRotate(node);
//     if (balanceFactor < -1 && value < node->right->data) // skewed kanan (right-left case)
//         return rightLeftZigzag(node);

//     return node;
// }

// AVLNode *findMinNode (AVLNode *node){
//     AVLNode *currNode = node;
//     while (currNode && currNode->left != NULL){
//         currNode = currNode->left;
//     }
//     return currNode;
// }
// AVLNode *removeAVL (AVLNode *node, int value){
//     if (node == NULL){
//         return node;
//     }
//     if (value > node->data){
//         node->right = removeAVL(node->right, value);
//     }
//     else if (value < node->data){
//         node->left = removeAVL(node->left, value);
//     }
//     // jika value == node->data (ketemu)
//     else {
//         AVLNode *temp;
//         // jika hanya memiliki 1 child node
//         if (node->left == NULL || node->right == NULL){
//             temp = NULL;
//             if (node->left == NULL){
//                 temp = node->right;
//             }
//             if (node->right == NULL){
//                 temp = node->left;
//             }
//             if (temp == NULL){
//                 temp = node;
//                 node = NULL;
//             }else {
//                 *node = *temp;
//             }
//             free(temp);
//         }else {
//             temp = findMinNode(node->right);
//             node->data = temp->data;
//             node->right = removeAVL(node->right, temp->data);
//         }
//     }
//     if(node==NULL) return node;
//     node->height = 1 + max(getHeight(node->left), getHeight(node->right));

//     int balanceFactor = getBalanceFactor(node);
//     if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0){
//         return leftCaseRotate(node);
//     }
//     if (balanceFactor > 1 && getBalanceFactor(node->left) < 0){
//         return leftRightZigzag(node);
//     }
//     if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0){
//         return rightCaseRotate(node);
//     }
//     if (balanceFactor < -1 && getBalanceFactor(node->right) > 0){
//         return rightLeftZigzag(node);
//     }
//     return node;
// }
// void init (AVL *avl){
//     avl->_root = NULL;
//     avl->size = 0u;
// }
// bool isEmpty(AVL *avl){
//     return avl->_root == NULL;
// }
// bool find (AVL *avl, int value){
//     AVLNode *temp = search(avl->_root, value);
//     if (temp == NULL){
//         return false;
//     }
//     if (temp->data == value){
//         return true;
//     }else {
//         return false;
//     }
// }
// void avl_insert (AVL *avl, int value){
//     // find = false 
//     if (!find(avl, value)){
//         avl->_root = insert(avl, avl->_root, value);
//         avl->size++;
//     }
// }
// void avl_remove (AVL *avl, int value){
//     if (find(avl, value)){
//         avl->_root = removeAVL(avl->_root, value);
//         avl->size--;
//     }
// }
// void preorder(AVLNode *root){
//     if (root){
//         preorder(root->left);
//         printf("%d", root->data);
//         preorder(root->right);
//     }
// }
// int main(int argc, char const *argv[])
// {
//     AVL avlku;
//     init(&avlku);
//     avl_insert(&avlku,1);
//     avl_insert(&avlku,2);
//     avl_insert(&avlku,3);
//     avl_insert(&avlku,4);
// 	avl_insert(&avlku,5);
// 	avl_insert(&avlku,7);
// 	avl_insert(&avlku,99);
// 	avl_insert(&avlku,12);
// 	avl_insert(&avlku,31);
// 	avl_remove(&avlku,1);
// 	avl_remove(&avlku,99);
// 	avl_remove(&avlku,4);
// 	avl_remove(&avlku,12);
// 	avl_remove(&avlku,31);
//     return 0;
// }


// ========[AVL Tree]======== //
/*
    Dibuat dan ditulis oleh ABDUR ROCHMAN
    28-03-2020
    Struktur Data 2020
    For C
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left,*right;
    int height;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

AVLNode* _avl_createNode(int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode* _search(AVLNode *root, int value) {
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

int _getHeight(AVLNode* node){
    if(node==NULL)
        return 0; 
    return node->height;
}

int _max(int a,int b){
    return (a > b)? a : b;
}

AVLNode* _rightRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->left;
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->right;
    pivotNode->right=newParrent->left;
    newParrent->left=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftCaseRotate(AVLNode* node){
    return _rightRotate(node);
}

AVLNode* _rightCaseRotate(AVLNode* node){
    return _leftRotate(node);
}

AVLNode* _leftRightCaseRotate(AVLNode* node){
    node->left=_leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode* _rightLeftCaseRotate(AVLNode* node){
    node->right=_rightRotate(node->right);
    return _leftRotate(node);
}

int _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value) {
    
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

AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

AVLNode* _remove_AVL(AVLNode* node,int value){
    if(node==NULL)
        return node;
    if(value > node->data)
    	node->right=_remove_AVL(node->right,value);
    else if(value < node->data)
    	node->left=_remove_AVL(node->left,value);
    else{
        AVLNode *temp;
        if((node->left==NULL)||(node->right==NULL)){
            temp=NULL;
            if(node->left==NULL) temp=node->right;  
            else if(node->right==NULL) temp=node->left;
            
            if(temp==NULL){
                temp=node;
                node=NULL;
            }
            else
                *node=*temp;   
            
            free(temp);
        }
        else{
            temp = _findMinNode(node->right);
            node->data=temp->data;
            node->right=_remove_AVL(node->right,temp->data);
        }    
    }

	if(node==NULL) return node;
    
    node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

    int balanceFactor= _getBalanceFactor(node);
    
    if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
        return _leftCaseRotate(node);

    if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
        return _leftRightCaseRotate(node);
  
    if(balanceFactor < -1 && _getBalanceFactor(node->right)<=0) 
        return _rightCaseRotate(node);

    if(balanceFactor < -1 && _getBalanceFactor(node->right)>0) 
        return _rightLeftCaseRotate(node);
    
    return node;
}

void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl,int value){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value);
        avl->_size++;
    }

}

void avl_remove(AVL *avl,int value){
    if(avl_find(avl,value)){
        avl->_root=_remove_AVL(avl->_root,value);
        avl->_size--;
    }

}

void preorder(AVLNode *root) {
    if (root) {
        preorder(root->left);
        printf("%d ", root->data);
        preorder(root->right);
    }
}

int main(){
    AVL avlku;
    avl_init(&avlku);
    avl_insert(&avlku,1);
    avl_insert(&avlku,2);
    avl_insert(&avlku,3);
    avl_insert(&avlku,4);
	avl_insert(&avlku,5);
	avl_insert(&avlku,7);
	avl_insert(&avlku,99);
	avl_insert(&avlku,12);
	avl_insert(&avlku,31);
	avl_remove(&avlku,1);
	avl_remove(&avlku,99);
	avl_remove(&avlku,4);
	avl_remove(&avlku,12);
	avl_remove(&avlku,31);

}