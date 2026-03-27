#include "bst.h"
#include <stdio.h>
#include <stdlib.h>


//-------------------------------------------------------------------------------------------------


typedef struct Node
{
    KeyType key;
    struct Node * left;
    struct Node * right;
} Node;
struct BST
{
    struct Node * root;
};


//-------------------------------------------------------------------------------------------------


Node * newNode(KeyType key)
{
    Node * newNode = malloc(sizeof(Node));

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
void deleteTree(Node * root)
{
    if (root == NULL) { return; }

    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

bool isInTree(Node * root, KeyType key)
{
    if (root == NULL) { return false; }
    if (key == root->key) { return true; }

    if (key < root->key) { return isInTree(root->left, key); }
    return isInTree(root->right, key);
}
Node * insertInTree(Node * root, KeyType key)
{
    if (root == NULL) { return newNode(key); }

    if (key < root->key) { root->left = insertInTree(root->left, key); }
    else if (key > root->key) { root->right = insertInTree(root->right, key); }
    
    return root;
}

void printKeys_inOrder(Node * root)
{
    if (root == NULL) { return; }

    printKeys_inOrder(root->left);
    printf("%d ", root->key);
    printKeys_inOrder(root->right);
}
void printKeys_preOrder(Node * root)
{
    if (root == NULL) { return; }

    printf("%d ", root->key);
    printKeys_preOrder(root->left);
    printKeys_preOrder(root->right);
}
void printKeys_postOrder(Node * root)
{
    if (root == NULL) { return; }

    printKeys_postOrder(root->left);
    printKeys_postOrder(root->right);
    printf("%d ", root->key);
}
void printTreeWithSpacing(Node * root, size_t level)
{
    if (root == NULL) { return; }

    for (size_t i = 0; i < level; i++) { printf("\t"); }
    printf("%d\n", root->key);
    printTreeWithSpacing(root->left, level + 1);
    printTreeWithSpacing(root->right, level + 1);
}


//-------------------------------------------------------------------------------------------------


BST * bst_new(void)
{
    BST * newBST = malloc(sizeof(BST));

    newBST->root = NULL;

    return newBST;
}
void bst_delete(BST * bst)
{
    deleteTree(bst->root);
    free(bst);
}

bool bst_search(BST * bst, KeyType key)
{
    return isInTree(bst->root, key);
}
BST * bst_insert(BST * bst, KeyType key)
{
    bst->root = insertInTree(bst->root, key);
    return bst;
}
// BST * bst_remove(BST * bst, KeyType key)
// {
//     // ...
// }

void bst_print_inOrder(BST * bst)
{
    printKeys_inOrder(bst->root);
    printf("\n");
}
void bst_print_preOrder(BST * bst)
{
    printKeys_preOrder(bst->root);
    printf("\n");
}
void bst_print_postOrder(BST * bst)
{
    printKeys_postOrder(bst->root);
    printf("\n");
}
void bst_visualize(BST * bst)
{
    printTreeWithSpacing(bst->root, 0);
    printf("\n");
}
