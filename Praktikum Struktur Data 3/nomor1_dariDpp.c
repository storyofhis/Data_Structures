//Pret Menata Pasukan
 
/*===== Libraries =====*/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
 
int urut = 1;
/*===== Node and AVL Structures =====*/
typedef struct AVLNode_t {
    char data[10000];
    struct AVLNode_t *left,*right;
    int height;
}AVLNode;
 
typedef struct AVL_t {
    AVLNode *_root;
    unsigned int _size;
}AVL;
 
/*===== Function List =====*/
AVLNode* _avl_createNode(char value[]) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    strcpy(newNode->data, value);
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
AVLNode* _search(AVLNode *root, char value[]) {
    while (root != NULL) {
        if (strcmp(value, root->data) < 0)
            root = root->left;
        else if (strcmp(value, root->data) > 0)
            root = root->right;
        else
            return root;
    }
    return root;
}
 
int _getHeight(AVLNode* node) {
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
 
    pivotNode->height=_max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
    newParrent->height=_max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;
 
    return newParrent;
}
 
AVLNode* _leftRotate(AVLNode* pivotNode) {
 
    AVLNode* newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;
 
    pivotNode->height=_max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
    newParrent->height=_max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;
 
    return newParrent;
}
 
AVLNode* _leftCaseRotate(AVLNode* node) {
    return _rightRotate(node);
}
 
AVLNode* _rightCaseRotate(AVLNode* node) {
    return _leftRotate(node);
}
 
AVLNode* _leftRightCaseRotate(AVLNode* node) {
    node->left = _leftRotate(node->left);
    return _rightRotate(node);
}
 
AVLNode* _rightLeftCaseRotate(AVLNode* node){
    node->right = _rightRotate(node->right);
    return _leftRotate(node);
}
 
int _getBalanceFactor(AVLNode* node) {
    if(node == NULL)
        return 0;
    return _getHeight(node->left) - _getHeight(node->right);
}
 
AVLNode* _insert_AVL(AVL *avl, AVLNode* node, char *value) {
    if(node == NULL) {
        return _avl_createNode(value);
    }
 
    if(strcmp(value, node->data) < 0)
        node->left = _insert_AVL(avl, node->left, value);
    else if(strcmp(value, node->data) > 0)
    	node->right = _insert_AVL(avl, node->right, value);
 
    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right)); 
 
    int balanceFactor = _getBalanceFactor(node);
 
    if(balanceFactor > 1 && strcmp(value, node->left->data) < 0) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && strcmp(value, node->left->data) > 0) // 
		return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && strcmp(value, node->right->data) > 0)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && strcmp(value, node->right->data) < 0)
        return _rightLeftCaseRotate(node);
 
    return node;
}
 
AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}
 
void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}
 
bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}
 
bool avl_find(AVL *avl, char value[]) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
 
    if (strcmp(value, temp->data) == 0) 
        return true;
    else
        return false;
}
 
void avl_insert(AVL *avl, char value[]){
    if(!avl_find(avl, value)){
        avl->_root = _insert_AVL(avl, avl->_root, value);
        avl->_size++;
    }
 
}
 
void __preorder(AVLNode *root) {
    if (root) {
        printf("%s\n", root->data);
        __preorder(root->left);
        __preorder(root->right);
    }
}
 
void __inorder(AVLNode *root) {
    if (root) {
        __inorder(root->left);
        if(urut == 1) {
            printf("%s", root->data);
            urut++;
        }
        else printf("_%s", root->data);
        __inorder(root->right);
    }
}
 
void __inorderNumber(AVLNode *root) {
    if (root) {
        __inorderNumber(root->left);
        printf("%d. %s \n", urut, root->data);
        urut++;
        __inorderNumber(root->right);
    }
}
 
 
void inorder(AVL *avl) {
    urut = 1;
    __inorder(avl->_root);
}
 
void inorderNumber(AVL *avl) {
    __inorderNumber(avl->_root);
}
 
/*===== Main Function =====*/
int main() {
    AVL pohon;
    avl_init(&pohon);
 
    char input[10000];
 
    while(scanf("%s", &input) != EOF) {
        avl_insert(&pohon, input);
    }
    inorderNumber(&pohon);
    inorder(&pohon);
 
    return 0;
}