#ifndef STUDENTS_LOADER
#define STUDENTS_LOADER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "structures/Student.h"
#include "structures/OrderedList.h"
#include "structures/BST.h"

Student *Students;

void initStudetsList(int n);
void buildList(List *list, int n);
void clearTree(BSTNode *root);

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

    fclose(fstudents);
}

void buildList(List *list, int n)
{
    int i = 0;

    if (list->first != NULL)
    {
        ListNode *current = list->first;
        do
        {
            i++;
            current = current->next;
        } while (current != NULL);
    }

    for(; i < n; i++){
        insertIntoList(list, Students + i);
    }
}

BSTNode *buildTree(int n)
{
    int i = 0;

    BSTNode *root = NULL;

    for(; i < n; i++){
        root = insertIntoTree(root, &Students[i]);
    }

    printf("%d -> %s\n", i, searchTree(root, Students[i].index)->firstname);
}

void clearTree(BSTNode *root)
{
    if (root == NULL) return;

    clearTree(root->left);
    clearTree(root->right);
    free(root);

    return;
}

#endif