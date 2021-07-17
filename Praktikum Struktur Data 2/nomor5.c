#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
    // membuat node baru
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
bool checkPrime (int value)
{
    if (value <= 1){
        return false;
    }
    for (int i = 2; i<=value/2; i++){
        if (value % i != 0){
            return true;
        }
        else {
            return false;
            break;
        }
    }
    return true;
}


BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL)
        return __bst__createNode(value);
    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode->left != NULL){
        currNode = currNode->left;
    }
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
    else {
        //  if (value == root->key)  // kalau udah ketemu
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

// inorder
void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d \n", root->key);
        __bst__inorder(root->right);
    }
}
void __bst__inorderGenap(BSTNode *root) {
    if (root) {
        __bst__inorderGenap(root->left);
        if (root->key % 2 == 0){
            printf("%d \n", root->key);
        }
        __bst__inorderGenap(root->right);
    }
}
void __bst__inorderGanjil(BSTNode *root) {
    if (root) {
        __bst__inorderGanjil(root->left);
        if (root->key % 2 != 0){
            printf("%d \n", root->key);
        }
        __bst__inorderGanjil(root->right);
    }
}
void __bst__inorderPrima(BSTNode *root){
    if (root){
        __bst__inorderPrima(root->left);
        if (checkPrime(root->key)){
            printf("%d\n", root->key);
        }
        __bst__inorderPrima(root->right);
    }
}



// postorder
void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d \n", root->key);
    }
}
void __bst__postorderGenap(BSTNode *root) {
    if (root) {
        __bst__postorderGenap(root->left);
        __bst__postorderGenap(root->right);
        if (root->key % 2 == 0){
            printf("%d \n", root->key);
        }
    }
}
void __bst__postorderGanjil(BSTNode *root) {
    if (root) {
        __bst__postorderGanjil(root->left);
        __bst__postorderGanjil(root->right);
        if (root->key % 2 != 0){
            printf("%d\n", root->key);
        }
    }
}
void __bst__postorderPrima(BSTNode *root){
    if (root){
        __bst__postorderPrima(root->left);
        __bst__postorderPrima(root->right);
        if (checkPrime(root->key)){
            printf("%d \n", root->key);
        }
    }
}


// preorder
void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d \n", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}
void __bst__preorderGenap(BSTNode *root) {
    if (root) {
        if (root->key == 0){
            printf("%d\n ", root->key);
        }
        __bst__preorderGenap(root->left);
        __bst__preorderGenap(root->right);
    }
}void __bst__preorderGanjil(BSTNode *root) {
    if (root) {
        if (root->key % 2 != 0){
            printf("%d \n", root->key);
        }
        __bst__preorderGanjil(root->left);
        __bst__preorderGanjil(root->right);
    }
}
void __bst__preorderPrima(BSTNode *root){
    if (root){
        if (checkPrime(root->key)){
            printf("%d \n", root->key);
        }
        __bst__preorderPrima(root->left);
        __bst__preorderPrima(root->right);
    }
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

// inorder
void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}
void bst_inorderGenap (BST *bst){
    __bst__inorderGenap(bst->_root);
}
void bst_inorderGanjil (BST *bst){
    __bst__inorderGanjil(bst->_root);
}
void bst_inorderPrima(BST *bst){
    __bst__inorderPrima(bst->_root);
}


// postorder
void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}
void bst_postorderGenap (BST *bst){
    __bst__postorderGenap(bst->_root);
}
void bst_postorderGanjil (BST *bst){
    __bst__postorderGanjil(bst->_root);
}
void bst_postorderPrima(BST *bst){
    __bst__postorderPrima(bst->_root);
}



// preorder
void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}
void bst_preorderGenap(BST *bst) {
    __bst__preorderGenap(bst->_root);
}
void bst_preorderGanjil(BST *bst) {
    __bst__preorderGanjil(bst->_root);
}
void bst_preorderPrima(BST *bst){
    __bst__preorderPrima(bst->_root);
}

int main()
{
    BST set;
    bst_init(&set);

    int n;
    char command[10], syarat[10];
    while(true) {
        scanf("%d", &n);
        if (n == -1){
            break;
        }
        bst_insert(&set, n);
    }

    int q;
    scanf("%d", &q);
    for (int i=1; i<=q; i++){
        scanf("%s %s", command, syarat);
        printf("Command : #%d\n", i);
        if (strcmp(command,"inorder") == 0)
        {
            if (strcmp(syarat,"genap") == 0){
                bst_inorderGenap(&set);
            }
            if (strcmp(syarat,"ganjil") == 0){
                bst_inorderGanjil(&set);
            }
            if (strcmp(syarat,"semua") == 0){
                bst_inorder(&set);
            }
            if (strcmp(syarat, "prima") == 0){
                bst_inorderPrima(&set);
            }
        }

        if (strcmp(command,"postorder") == 0)
        {
            if (strcmp(syarat,"genap") == 0){
                bst_postorderGenap(&set);
            }
            if (strcmp(syarat,"ganjil") == 0){
                bst_postorderGanjil(&set);
            }
            if (strcmp(syarat,"semua") == 0){
                bst_postorder(&set);
            }
            if (strcmp(syarat, "prima") == 0){
                bst_postorderPrima(&set);
            }
        }

        if (strcmp(command,"preorder") == 0)
        {
            if (strcmp(syarat,"genap") == 0){
                bst_preorderGenap(&set);
            }
            if (strcmp(syarat,"ganjil") == 0){
                bst_preorderGanjil(&set);
            }
            if (strcmp(syarat,"semua") == 0){
                bst_preorder(&set);
            }
            if (strcmp(syarat, "prima") == 0){
                bst_preorderPrima(&set);
            }
        }
    }

    return 0;
}

























































// /**
//  * Implementasi Binary Search Tree (ADT: BST)
//  * yakni BST yang tidak menyimpan key duplikat (unique key)
//  * 
//  * Dibuat dan ditulis oleh Bayu Laksana
//  * -- tanggal 29 Februrari 2019
//  * Struktur Data 2020
//  * 
//  * Implementasi untuk Bahasa C
//  */

// #include <stdlib.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// /**
//  * Node structure and
//  * uniqueBST structure
//  */

// typedef struct bstnode_t {
//     int key;
//     struct bstnode_t \
//         *left, *right;
// } BSTNode;

// typedef struct bst_t {
//     BSTNode *_root;
//     unsigned int _size;
// } BST;

// /**
//  * !!! WARNING UTILITY FUNCTION !!!
//  * Recognized by prefix "__bst__"
//  * ---------------------------------------------
//  * Note that you better never access these functions, 
//  * unless you need to modify or you know how these functions work.
//  */

// BSTNode* __bst__createNode(int value) {
//     // membuat node baru
//     BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
//     newNode->key = value;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }
// // bool checkPrime (BSTNode *root){
// //     if (root->key == 2)
// //         return true;
// //     for(int i = 2; i<root->key; i++)
// //     {
// //         if (root->key % i == 0){
// //             return false;
// //         }else {
// //             return true;
// //         }
// //     }
// // }
// bool checkPrime (int value)
// {
//     if (value == 2)
//         return true;
//     for(int i = 2; i<value; i++)
//     {
//         if (value % i == 0){
//             return false;
//         }else {
//             return true;
//         }
//     }
//     return (value != 1 && checkPrime(value) == true);
// }


// BSTNode* __bst__insert(BSTNode *root, int value) {
//     if (root == NULL)
//         return __bst__createNode(value);
//     if (value < root->key)
//         root->left = __bst__insert(root->left, value);
//     else if (value > root->key)
//         root->right = __bst__insert(root->right, value);
//     return root;
// }

// BSTNode* __bst__search(BSTNode *root, int value) {
//     while (root != NULL) {
//         if (value < root->key)
//             root = root->left;
//         else if (value > root->key)
//             root = root->right;
//         else
//             return root;
//     }
//     return root;
// }

// BSTNode* __bst__findMinNode(BSTNode *node) {
//     BSTNode *currNode = node;
//     while (currNode->left != NULL){
//         currNode = currNode->left;
//     }
//     return currNode;
// }

// BSTNode* __bst__remove(BSTNode *root, int value) {
//     if (root == NULL) return NULL;

//     if (value > root->key) 
//         root->right = __bst__remove(root->right, value);
//     else if (value < root->key) 
//         root->left = __bst__remove(root->left, value);
//     else {
//         //  if (value == root->key)  // kalau udah ketemu
//         if (root->left == NULL) {
//             BSTNode *rightChild = root->right;
//             free(root);
//             return rightChild;
//         }
//         else if (root->right == NULL) {
//             BSTNode *leftChild = root->left;
//             free(root);
//             return leftChild;
//         }

//         BSTNode *temp = __bst__findMinNode(root->right);
//         root->key     = temp->key;
//         root->right   = __bst__remove(root->right, temp->key);
//     }
//     return root;
// }

// // inorder
// void __bst__inorder(BSTNode *root) {
//     if (root) {
//         __bst__inorder(root->left);
//         printf("%d \n", root->key);
//         __bst__inorder(root->right);
//     }
// }
// void __bst__inorderGenap(BSTNode *root) {
//     if (root) {
//         __bst__inorderGenap(root->left);
//         if (root->key % 2 == 0){
//             printf("%d \n", root->key);
//         }
//         __bst__inorderGenap(root->right);
//     }
// }
// void __bst__inorderGanjil(BSTNode *root) {
//     if (root) {
//         __bst__inorderGanjil(root->left);
//         if (root->key % 2 != 0){
//             printf("%d \n", root->key);
//         }
//         __bst__inorderGanjil(root->right);
//     }
// }
// void __bst__inorderPrima(BSTNode *root){
//     if (root){
//         __bst__inorderPrima(root->left);
//         if (checkPrime(root->key) == true){
//             printf("%d\n", root->key);
//         }
//         __bst__inorderPrima(root->right);
//         // __bst__inorderPrima(root->left, n, q);
//         // for (int j = 1; j <= q; j++){
//         //     if (root->key == 2){
//         //         printf("%d\n", root->key);
//         //     }else {
//         //         for (int i = 2; i<= n; i++){
//         //             j = i;
//         //             if (n % i != 0){
//         //                 printf("%d\n", root->key);
                                
//         //             }
//         //         }
//         //     }
//         // }
//         // __bst__inorderPrima(root->right, n, q);
//     }
// }



// // postorder
// void __bst__postorder(BSTNode *root) {
//     if (root) {
//         __bst__postorder(root->left);
//         __bst__postorder(root->right);
//         printf("%d \n", root->key);
//     }
// }
// void __bst__postorderGenap(BSTNode *root) {
//     if (root) {
//         __bst__postorderGenap(root->left);
//         __bst__postorderGenap(root->right);
//         if (root->key % 2 == 0){
//             printf("%d \n", root->key);
//         }
//     }
// }
// void __bst__postorderGanjil(BSTNode *root) {
//     if (root) {
//         __bst__postorderGanjil(root->left);
//         __bst__postorderGanjil(root->right);
//         if (root->key % 2 != 0){
//             printf("%d\n", root->key);
//         }
//     }
// }
// void __bst__postorderPrima(BSTNode *root){
//     if (root){
//         __bst__postorderPrima(root->left);
//         __bst__postorderPrima(root->right);
//         if (checkPrime(root->key) == true){
//             printf("%d \n", root->key);
//         }
//     }
// }


// // preorder
// void __bst__preorder(BSTNode *root) {
//     if (root) {
//         printf("%d \n", root->key);
//         __bst__preorder(root->left);
//         __bst__preorder(root->right);
//     }
// }
// void __bst__preorderGenap(BSTNode *root) {
//     if (root) {
//         if (root->key == 0){
//             printf("%d\n ", root->key);
//         }
//         __bst__preorderGenap(root->left);
//         __bst__preorderGenap(root->right);
//     }
// }void __bst__preorderGanjil(BSTNode *root) {
//     if (root) {
//         if (root->key % 2 != 0){
//             printf("%d \n", root->key);
//         }
//         __bst__preorderGanjil(root->left);
//         __bst__preorderGanjil(root->right);
//     }
// }
// void __bst__preorderPrima(BSTNode *root){
//     if (root){
//         if (checkPrime(root->key)==true){
//             printf("%d \n", root->key);
//         }
//         __bst__preorderPrima(root->left);
//         __bst__preorderPrima(root->right);
//         // __bst__preorderPrima(root->left, q);
//         // if (root->key == 2){
//         //     printf("%d\n", root->key);
//         // }else {
//         //     int stat;
//         //     for (int i = 2; i<  q; i++){
//         //         if (q % i == 0){
//         //             stat = 0;
//         //             break;
//         //         }else {
//         //             stat = 1;
//         //         }
//         //     }
//         //     if (stat == 1){
//         //         printf("%d\n", root->key);
//         //     }
//         // }
//         // __bst__preorderPrima(root->right, q);
//     }
// }

// /**
//  * PRIMARY FUNCTION
//  * ---------------------------
//  * Accessible and safe to use.
//  */

// void bst_init(BST *bst) {
//     bst->_root = NULL;
//     bst->_size = 0u;
// }

// bool bst_isEmpty(BST *bst) {
//     return bst->_root == NULL;
// }

// bool bst_find(BST *bst, int value) {
//     BSTNode *temp = __bst__search(bst->_root, value);
//     if (temp == NULL)
//         return false;
    
//     if (temp->key == value)
//         return true;
//     else
//         return false;
// }

// void bst_insert(BST *bst, int value) {
//     if (!bst_find(bst, value)) {
//         bst->_root = __bst__insert(bst->_root, value);
//         bst->_size++;
//     }
// }

// void bst_remove(BST *bst, int value) {
//     if (bst_find(bst, value)) {
//         bst->_root = __bst__remove(bst->_root, value);
//         bst->_size--;
//     }
// }

// /**
//  * Binary search tree traversal
//  * - Inorder
//  * - Postorder
//  * - Preorder
//  */

// // inorder
// void bst_inorder(BST *bst) {
//     __bst__inorder(bst->_root);
// }
// void bst_inorderGenap (BST *bst){
//     __bst__inorderGenap(bst->_root);
// }
// void bst_inorderGanjil (BST *bst){
//     __bst__inorderGanjil(bst->_root);
// }
// void bst_inorderPrima(BST *bst){
//     __bst__inorderPrima(bst->_root);
// }


// // postorder
// void bst_postorder(BST *bst) {
//     __bst__postorder(bst->_root);
// }
// void bst_postorderGenap (BST *bst){
//     __bst__postorderGenap(bst->_root);
// }
// void bst_postorderGanjil (BST *bst){
//     __bst__postorderGanjil(bst->_root);
// }
// void bst_postorderPrima(BST *bst){
//     __bst__postorderPrima(bst->_root);
// }



// // preorder
// void bst_preorder(BST *bst) {
//     __bst__preorder(bst->_root);
// }
// void bst_preorderGenap(BST *bst) {
//     __bst__preorderGenap(bst->_root);
// }
// void bst_preorderGanjil(BST *bst) {
//     __bst__preorderGanjil(bst->_root);
// }
// void bst_preorderPrima(BST *bst){
//     __bst__preorderPrima(bst->_root);
// }

// int main()
// {
//     BST set;
//     bst_init(&set);

//     int n;
//     char command[1001], syarat[1001];
//     while(1) {
//         scanf("%d", &n);
//         if (n == -1){
//             break;
//         }
//         bst_insert(&set, n);
//     }

//     int q;
//     scanf("%d", &q);
//     for (int i=1; i<=q; i++){
//         scanf("%s %s", command, syarat);
//         // scanf("%s", syarat);
//         printf("Command : #%d\n", i);
//         if (strcmp(command,"inorder") == 0)
//         {
//             if (strcmp(syarat,"genap") == 0){
//                 bst_inorderGenap(&set);
//             }
//             if (strcmp(syarat,"ganjil") == 0){
//                 bst_inorderGanjil(&set);
//             }
//             if (strcmp(syarat,"semua") == 0){
//                 bst_inorder(&set);
//             }
//             if (strcmp(syarat, "prima") == 0){
//                 bst_inorderPrima(&set);
//             }
//         }

//         if (strcmp(command,"postorder") == 0)
//         {
//             if (strcmp(syarat,"genap") == 0){
//                 bst_postorderGenap(&set);
//             }
//             if (strcmp(syarat,"ganjil") == 0){
//                 bst_postorderGanjil(&set);
//             }
//             if (strcmp(syarat,"semua") == 0){
//                 bst_postorder(&set);
//             }
//             if (strcmp(syarat, "prima") == 0){
//                 bst_postorderPrima(&set);
//             }
//         }

//         if (strcmp(command,"preorder") == 0)
//         {
//             if (strcmp(syarat,"genap") == 0){
//                 bst_preorderGenap(&set);
//             }
//             if (strcmp(syarat,"ganjil") == 0){
//                 bst_preorderGanjil(&set);
//             }
//             if (strcmp(syarat,"semua") == 0){
//                 bst_preorder(&set);
//             }
//             if (strcmp(syarat, "prima") == 0){
//                 bst_preorderPrima(&set);
//             }
//         }
//     }

//     return 0;
// }



// #include<stdio.h>
// int main() {
//  int bilangan, angka, stat;
 
//  printf("--- Program Penentu Bilangan Prima atau Bukan ---");
//  printf("\n________________________________________________");
//  printf("\nMasukkan bilangan: ");
//  scanf("%d", &bilangan);
 
//  if(bilangan <= 1) {
//   printf("Masukkan angka lebih dari 1.");
//  }else{
//   if(bilangan == 2){
//    printf("%d merupakan bilangan prima.", bilangan);
//   }else{
//    for(angka=2; angka<bilangan; angka++){
//     if(bilangan %angka == 0){
//      stat = 0;
//      break;
//     }else{
//      stat = 1;
//     }
//    }
   
//    if(stat == 0){
//     printf("%d merupakan bukan bilangan prima.\n", bilangan);
//    }else{
//     printf("%d merupakan bilangan prima.", bilangan);
//    }
//   }
//  }
// }