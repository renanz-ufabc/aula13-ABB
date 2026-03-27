#ifndef BST_H
#define BST_H
#include <stdbool.h>


typedef int KeyType;
typedef struct BST BST;


BST * bst_new(void);
void bst_delete(BST * bst);

bool bst_search(BST * bst, KeyType key);
BST * bst_insert(BST * bst, KeyType key);
// BST * bst_remove(BST * bst, KeyType key);

void bst_print_inOrder(BST * bst);
void bst_print_preOrder(BST * bst);
void bst_print_postOrder(BST * bst);
void bst_visualize(BST * bst);


#endif
