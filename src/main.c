#include <stdio.h>
#include "bst.h"


int main(void)
{
    BST * t = bst_new();
    
    KeyType keys[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    const size_t size = 9;
    for (size_t i = 0; i < size; i++)
    {
        bst_insert(t, keys[i]);
    }

    bst_visualize(t);
    bst_print_inOrder(t);
    bst_remove(t, 13);
    bst_remove(t, 10);
    bst_remove(t, 6);
    bst_remove(t, 8);
    bst_remove(t, 0);
    bst_visualize(t);
    bst_print_inOrder(t);

    bst_delete(t);

    return 0;
}
