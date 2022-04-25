#include "StudentsLoader.h"

int main()
{
    initStudetsList(1000000);
    BSTNode *tree;

    tree = buildTree(10);

    printf("In order: \n\n");

    inOrder(tree);

    printf("\n\nPre order: \n\n");

    preOrder(tree);

    printf("\n\nPost order: \n\n");

    postOrder(tree);

    free(tree);
    free(Students);

    return 0;
}
