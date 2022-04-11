#include "StudentsLoader.h"
#include <time.h>

int main()
{
    initStudetsList(1000000);
    BSTNode *tree = (BSTNode *)calloc(1, sizeof(BSTNode));

    printf("Time to insert 50 items into list\n");

    for (int j = 1; j <= 100; j += 2)
    {
        int n = 1000 * j;

        clock_t begin = clock();

        tree = buildTree(n);

        clock_t end = clock();
        printf("%d - %fms\n", n, (double)(end - begin) / CLOCKS_PER_SEC * 1000);

        clearTree(tree);
        tree = NULL;
    }

    printf("Time to delete n items from list\n");

    for (int j = 1; j <= 100; j += 2)
    {
        int n = 250 * j;

        tree = buildTree(n);

        int toDelete[n];

        int i;

        for (i = 0; i < n; i++)
        {
            toDelete[i] = i;
        }

        int temp, k;

        for (i = n - 1; i >= 0; i--)
        {
            k = rand() % (n - 1);
            temp = toDelete[k];
            toDelete[k] = toDelete[i];
            toDelete[i] = temp;
        }

        clock_t begin = clock();

        for (i = 0; i < n; i++)
        {
            tree = deleteFromTree(tree, Students[toDelete[i]].index);
        }

        clock_t end = clock();
        printf("%d - %fms\n", n, (double)(end - begin) / CLOCKS_PER_SEC * 1000);

        clearTree(tree);
        tree = NULL;
    }

    printf("Avg time to search item from list\n");

    for (int j = 1; j <= 100; j += 2)
    {
        int n = 250 * j;

        tree = buildTree(n);

        int i;

        clock_t begin = clock();

        for (i = 0; i < n; i++)
        {
            searchTree(tree, Students[i].index);
        }

        clock_t end = clock();
        printf("%d - %fms\n", n, (double)(end - begin) / CLOCKS_PER_SEC * 1000);

        clearTree(tree);
        tree = NULL;
    }

    free(tree);
    free(Students);

    return 0;
}
