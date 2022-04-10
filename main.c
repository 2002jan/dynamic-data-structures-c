#include "StudentsLoader.h"
#include <time.h>

int main()
{
    initStudetsList(1000000);
    List *list = calloc(1, sizeof(List));

    printf("Time to insert 50 items into list\n");

    for (int j = 1; j <= 100; j+= 4)
    {
        int n = 5000 * j;

        buildList(list, n);

        clock_t begin = clock();

        for (int i = 0; i < 50; i++)
        {
            insertIntoList(list, &Students[n + i]);
        }
        clock_t end = clock();
        printf("%d - %fms\n", n, (double)(end - begin) / CLOCKS_PER_SEC * 1000);
    }

    free(list);
    free(Students);

    return 0;
}
