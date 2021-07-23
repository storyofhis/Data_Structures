#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int item;
    struct node* left;
    struct node* right;
};
// Inorder traversal 
void inorderTraversal(struct node *root){
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ->", root->item);
    inorderTraversal(root->right);
}
// preOrder traversal 
void preorderTraversal(struct node *root){
    if (root == NULL) return;
    printf("%d ->", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
// Postorder traversal
void postorderTraversal(struct node *root){
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->item);
}
struct node *createNode(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode){
        newNode->item = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }
}
struct node *insertLeft (struct node *root, int value){
    root->left = createNode(value);
    return(root->left);
}
struct node *insertRight (struct node *root, int value){
    root->right = createNode(value);
    return(root->right);
}
int main(int argc, char const *argv[])
{
    struct node *root = createNode(1);
    insertLeft(root, 12);
    insertRight(root, 9);

    insertLeft(root->left, 5);
    insertRight(root->left, 6);

    printf("Inorder traversal \n");
    inorderTraversal(root);

    printf("\nPreorder traversal \n");
    preorderTraversal(root);

    printf("\nPostorder traversal \n");
    postorderTraversal(root);
    return 0;
}
