#include <stdio.h>
#include "bst.h"


int main(void)
{
    BST * t = bst_new();
    
    KeyType keys[] = {50, 10, 70, 60, 80, 9, 11};
    const size_t size = 7;
    for (size_t i = 0; i < size; i++)
    {
        bst_insert(t, keys[i]);
    }

    bst_visualize(t);

    bst_delete(t);

    return 0;
}
