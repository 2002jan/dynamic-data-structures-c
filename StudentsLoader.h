#ifndef STUDENTS_LOADER
#define STUDENTS_LOADER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "structures/Student.h"

Student *Students;

void initStudetsList(int n);


void initStudetsList(int n)
{
    Students = (Student *)malloc(sizeof(Student) * n);

    FILE *fstudents = fopen("students.csv", "r");

    if(fstudents == NULL){
        printf("Could not open students.csv :(");
        exit(1);
    }

    char lineBuffer[40];
    char *token;

    int j = 0;
    while (fgets(lineBuffer, 40, fstudents) != NULL && j < n)
    {
        size_t len = strlen(lineBuffer);

        if (lineBuffer[len - 1] != '\n' && j != n - 1)
        {
            printf("File not supported, to long line.\n");
            exit(1);
        }

        token = strtok(lineBuffer, " \n\r,");
        strcpy(Students[j].firstname, token);
        token = strtok(NULL, " \n\r,");
        strcpy(Students[j].lastname, token);
        token = strtok(NULL, " \n\r,");
        Students[j].index = atol(token);
        j++;    
    }
    
    j = 999999;

    printf("%d. %s %s - %d\n", j + 1, Students[j].firstname, Students[j].lastname, Students[j].index);

    free(token);
}

#endif