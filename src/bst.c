#include "bst.h"
#include <stdio.h>
#include <stdlib.h>


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


/// PRIVATE FUNCTIONS ...........................

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
Node * newNode(KeyType key)
{
    Node * newNode = malloc(sizeof(Node));

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
Node * insertInTree(Node * root, KeyType key)
{
    if (root == NULL) { return newNode(key); }
    
    if (key < root->key) { root->left = insertInTree(root->left, key); }
    else if (key > root->key) { root->right = insertInTree(root->right, key); }
    
    return root;
}
Node * minNode(Node * root)
{
    if (root == NULL) { return NULL; }
    if (root->left == NULL) { return root; }

    return minNode(root->left);
}
Node * successor(Node * node)
{
    return minNode(node->right);
}
Node * removeFromTree(Node * root, KeyType key)
{
    if (root == NULL) { return NULL; }

    if (key < root->key) { root->left = removeFromTree(root->left, key); }
    else if (key > root->key) { root->right = removeFromTree(root->right, key); }
    else
    {
        if (root->left == NULL)
        {
            Node * trash = root;
            root = root->right;
            free(trash);
        }
        else if (root->right == NULL)
        {
            Node * trash = root;
            root = root->left;
            free(trash);
        }
        else
        {
            Node * succ = successor(root);
            root->key = succ->key;
            root->right = removeFromTree(root->right, succ->key);
        }
    }

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
void printTree(Node * root, size_t level)
{
    if (root == NULL) { return; }

    for (size_t i = 0; i < level; i++) { printf("\t"); }
    printf("%d\n", root->key);
    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
}
void printTree_labels(Node * root, size_t level, int side)
{
    if (root == NULL) { return; }

    for (size_t i = 0; i < level; i++) { printf("\t"); }
    
    switch (side)
    {
        case -1: printf("<< %d\n", root->key); break;
        case 0: printf("%d\n", root->key); break;
        case 1: printf(">> %d\n", root->key); break;
    }

    printTree_labels(root->left, level + 1, -1);
    printTree_labels(root->right, level + 1, 1);
}
int max(int x, int y)
{
    return (x > y) ? x : y;
}
int calcHeight(Node * node)
{
    if (node == NULL) { return 0; }

    return 1 + max(calcHeight(node->left), calcHeight(node->right));
}
int calcBalanceFactor(Node * node)
{
    if (node == NULL) { return 0; }

    return calcHeight(node->left) - calcHeight(node->right);
}
void printTree_info(Node * root, size_t level, int side)
{
    if (root == NULL) { return; }

    for (size_t i = 0; i < level; i++) { printf("\t"); }
    
    switch (side)
    {
        case -1: printf("<< %d [h=%d, bf=%d]\n", root->key, calcHeight(root), calcBalanceFactor(root)); break;
        case 0: printf("%d [h=%d, bf=%d]\n", root->key, calcHeight(root), calcBalanceFactor(root)); break;
        case 1: printf(">> %d [h=%d, bf=%d]\n", root->key, calcHeight(root), calcBalanceFactor(root)); break;
    }

    printTree_info(root->left, level + 1, -1);
    printTree_info(root->right, level + 1, 1);
}


/// INTERFACE IMPLEMENTATION ....................

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
void bst_insert(BST * bst, KeyType key)
{
    bst->root = insertInTree(bst->root, key);
}
void bst_remove(BST * bst, KeyType key)
{
    bst->root = removeFromTree(bst->root, key);
}

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
    printTree_info(bst->root, 0, 0);
}
