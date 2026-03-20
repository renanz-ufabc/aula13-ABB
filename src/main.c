#include <stdio.h>
#include "bst.c"


int main(void)
{
    BST * tree = ___sampleBST();
    int searchedKeys[] = {48, 58, 10};
    const int searchedKeysN = 3;

    for (int i = 0; i < searchedKeysN; i++)
    {
        printf("%d: %sfound\n", searchedKeys[i], search_iterative(tree, searchedKeys[i]) ? "" : "not");
    }

    return 0;
}
