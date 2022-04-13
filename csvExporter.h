#ifndef PATH_MAX
#define PATH_MAX 260
#endif

#ifndef CSV_EXPORTER
#define CSV_EXPORTER

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

char output_path[] = ".\\output";

void exportToCsv(int *ns, double *time, int n, char *exerciseName, char *algorithmName);

void checkSubdirectory(char *path);

void checkSubdirectory(char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1)
    {
        mkdir(path);
    }
}

void exportToCsv(int *ns, double *time, int n, char *exerciseName, char *algorithmName)
{
    checkSubdirectory(output_path);

    char *path = (char *)malloc(sizeof(char) * PATH_MAX);

    sprintf(path, "%s\\output_%s_%s.csv", output_path, exerciseName, algorithmName);
    
    FILE *csv;
    
    csv = fopen(path, "w+");

    if(csv == NULL)
    {
        printf("Error while opening/creating csv file!");
        exit(1);
        free(path);
    }

    int i;

    fprintf(csv, "Number of elements, Execution time\n");

    for (i = 0; i < n; i++)
    {
        fprintf(csv, "%d, %f\n", ns[i], time[i]);
    }

    fclose(csv);
    free(path);
    
}

#endif