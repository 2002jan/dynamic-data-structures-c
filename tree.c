#include "StudentsLoader.h"
#include <time.h>
#include "csvExporter.h"

int main()
{
    int runs = 15;

    initStudetsList(1000000);
    BSTNode *tree;

    int *ns;
    double *times;

    ns = (int *)calloc(runs, sizeof(int));
    times = (double *)calloc(runs, sizeof(double));

    printf("Time to insert n items into BST\n");

    for (int j = 1; j <= runs; j++)
    {
        int n = 10000 * j;
        ns[j - 1] = n;
        times[j - 1] = 0;

        for (int i = 0; i < 25; i++)
        {
            clock_t begin = clock();

            tree = buildTree(n);

            clock_t end = clock();
            times[j - 1] += (double)(end - begin) / CLOCKS_PER_SEC * 1000;

            clearTree(tree);
            tree = NULL;
        }

        times[j - 1] /= 25;

        printf("%d - %fms\n", n, times[j - 1]);
    }

    exportToCsv(ns, times, runs, "BST", "Insertion");

    printf("Time to insert n items into BBST\n");

    for (int j = 1; j <= runs; j++)
    {
        int n = 10000 * j;
        ns[j - 1] = n;
        times[j - 1] = 0;

        for (int i = 0; i < 25; i++)
        {
            clock_t begin = clock();

            tree = buildTree(n);
            tree = balanceTree(tree, n);

            clock_t end = clock();
            times[j - 1] += (double)(end - begin) / CLOCKS_PER_SEC * 1000;

            clearTree(tree);
            tree = NULL;
        }

        times[j - 1] /= 25;

        printf("%d - %fms\n", n, times[j - 1]);
    }

    exportToCsv(ns, times, runs, "BBST", "Insertion");

    printf("Time to delete n items from BST\n");

    for (int j = 1; j <= runs; j++)
    {
        int n = 10000 * j;
        ns[j - 1] = n;
        times[j - 1] = 0;

        for (int jj = 0; jj < 25; jj++)
        {
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

            times[j - 1] += (double)(end - begin) / CLOCKS_PER_SEC * 1000;

            clearTree(tree);
            tree = NULL;
        }

        times[j - 1] /= 25;

        printf("%d - %fms\n", n, times[j - 1]);
    }

    exportToCsv(ns, times, runs, "BST", "Deletion");

    printf("Time to delete n items from BBST\n");

    for (int j = 1; j <= runs; j++)
    {
        int n = 10000 * j;
        ns[j - 1] = n;
        times[j - 1] = 0;

        for (int jj = 0; jj < 25; jj++)
        {
            tree = buildTree(n);
            tree = balanceTree(tree, n);

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

            times[j - 1] += (double)(end - begin) / CLOCKS_PER_SEC * 1000;

            clearTree(tree);
            tree = NULL;
        }

        times[j - 1] /= 25;

        printf("%d - %fms\n", n, times[j - 1]);
    }

    exportToCsv(ns, times, runs, "BBST", "Deletion");

    printf("Avg time to search item from BST\n");

    for (int j = 1; j <= runs; j++)
    {
        int n = 10000 * j;

        ns[j - 1] = n;
        times[j - 1] = 0;

        for (int jj = 0; jj < 25; jj++)
        {
            tree = buildTree(n);

            int i;

            clock_t begin = clock();

            for (i = 0; i < n; i++)
            {
                searchTree(tree, Students[i].index);
            }

            clock_t end = clock();

            times[j - 1] += (double)(end - begin) / CLOCKS_PER_SEC * 1000;

            clearTree(tree);
            tree = NULL;
        }

        times[j - 1] /= 25;

        printf("%d - %fms\n", n, times[j - 1]);
    }

    exportToCsv(ns, times, runs, "BST", "Search");

    printf("Avg time to search item from BBST\n");

    for (int j = 1; j <= runs; j++)
    {
        int n = 10000 * j;

        ns[j - 1] = n;
        times[j - 1] = 0;

        for (int jj = 0; jj < 25; jj++)
        {
            tree = buildTree(n);
            tree = balanceTree(tree, n);

            int i;

            clock_t begin = clock();

            for (i = 0; i < n; i++)
            {
                searchTree(tree, Students[i].index);
            }

            clock_t end = clock();

            times[j - 1] += (double)(end - begin) / CLOCKS_PER_SEC * 1000;

            clearTree(tree);
            tree = NULL;
        }

        times[j - 1] /= 25;

        printf("%d - %fms\n", n, times[j - 1]);
    }

    exportToCsv(ns, times, runs, "BBST", "Search");

    free(tree);
    free(Students);

    return 0;
}
