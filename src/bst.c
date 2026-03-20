#include <stdbool.h>
#include <stdlib.h>


typedef struct Node
{
    int key;
    struct Node * left;
    struct Node * right;
} Node;
typedef struct BST
{
    struct Node * root;
} BST;


Node * newNode(int key)
{
    Node * newNode = malloc(sizeof(Node));

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
void deleteNode(Node * node)
{
    // recursive destruction...
}

BST * newBST(Node * root)
{
    BST * newBST = malloc(sizeof(BST));

    newBST->root = root;

    return newBST;
}
void deleteBST(BST * bst)
{
    deleteNode(bst->root);
    free(bst);
}


bool search_iterative(BST * bst, int key)
{
    Node * curr = bst->root;

    while (curr != NULL)
    {
        if (key == curr->key) { return true; }

        if (key < curr->key) { curr = curr->left; }
        else { curr = curr->left; }
    }

    return false;
}
bool search_recursive(Node * node, int key)
{
    if (node == NULL) { return false; }
    if (key == node->key) { return true; }

    if (key < node->key) { return search_recursive(node->left, key); }
    return search_recursive(node->right, key);
}

BST * ___sampleBST(void)
{
    Node * root = newNode(50);
    root->left = newNode(43);
    root->left->left = newNode(3);
    root->left->right = newNode(48);
    root->left->right->left = newNode(45);
    root->right = newNode(61);
    root->right->left = newNode(58);
    root->right->right = newNode(70);

    return newBST(root);
}
