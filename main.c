#include "StudentsLoader.h"
#include <time.h>
#include "csvExporter.h"

int main()
{
    int runs = 50;

    initStudetsList(1000000);
    List *list = calloc(1, sizeof(List));

    ListNode *current, *next;
    int *ns; 
    double *times;

    ns = (int *)calloc(runs, sizeof(int));
    times = (double *)calloc(runs, sizeof(double));

    printf("Time to insert 50 items into list\n");

    for (int j = 1; j <= runs; j++)
    {
        int n = 10000 * j;

        clock_t begin = clock();

        buildList(list, n);

        clock_t end = clock();
        
        ns[j - 1] = n;
        times[j - 1] = (double)(end - begin) / CLOCKS_PER_SEC * 1000;

        printf("%d - %fms\n", n, times[j - 1]);

        current = list->first;
        list->first = NULL;

        while (current != NULL)
        {
            next = current->next;
            free(current);
            current = next;
        }
    }

    exportToCsv(ns, times, runs, "OLL", "Insertion");

    printf("Time to delete n items from list\n");

    for (int j = 1; j <= runs; j++)
    {
        int n = 10000 * j;

        buildList(list, n);

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
            deleteFromList(list, Students[toDelete[i]].index);
        }

        clock_t end = clock();
        
        ns[j - 1] = n;
        times[j - 1] = (double)(end - begin) / CLOCKS_PER_SEC * 1000;

        printf("%d - %fms\n", n, times[j - 1]);
    }

    exportToCsv(ns, times, runs, "OLL", "Deletion");

    current = list->first, *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    printf("Avg time to search item from list\n");

    for (int j = 1; j <= runs; j++)
    {
        int n = 10000 * j;

        buildList(list, n);

        int i;

        clock_t begin = clock();

        for (i = 0; i < n; i++)
        {
            searchList(list, Students[i].index);
        }

        clock_t end = clock();
        
        ns[j - 1] = n;
        times[j - 1] = (double)(end - begin) / CLOCKS_PER_SEC * 1000;

        printf("%d - %fms\n", n, times[j - 1]);
    }

    exportToCsv(ns, times, runs, "OLL", "Search");

    free(list);
    free(Students);

    return 0;
}
