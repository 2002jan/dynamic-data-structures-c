#include "StudentsLoader.h"
#include <time.h>

int main()
{
    initStudetsList(1000000);
    List *list = calloc(1, sizeof(List));

    ListNode *current = list->first, *next;

    printf("Time to insert 50 items into list\n");

    for (int j = 1; j <= 100; j += 2)
    {
        int n = 250 * j;

        clock_t begin = clock();

        buildList(list, n);

        clock_t end = clock();
        printf("%d - %fms\n", n, (double)(end - begin) / CLOCKS_PER_SEC * 1000);

        list->first = NULL;

        while (current != NULL)
        {
            next = current->next;
            free(current);
            current = next;
        }
    }

    printf("Time to delete n items from list\n");

    for (int j = 1; j <= 100; j += 2)
    {
        int n = 250 * j;

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
        printf("%d - %fms\n", n, (double)(end - begin) / CLOCKS_PER_SEC * 1000);
    }

    current = list->first, *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    printf("Avg time to search item from list\n");

    for (int j = 1; j <= 100; j += 2)
    {
        int n = 250 * j;

        buildList(list, n);

        int i;

        clock_t begin = clock();

        for (i = 0; i < n; i++)
        {
            searchList(list, Students[i].index);
        }

        clock_t end = clock();
        printf("%d - %fms\n", n, (double)(end - begin) / CLOCKS_PER_SEC * 1000);
    }

    free(list);
    free(Students);

    return 0;
}
