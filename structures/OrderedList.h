#ifndef ORDERED_LIST
#define ORDERED_LIST

#include <stdlib.h>
#include "Student.h"

typedef struct ListNode
{
    Student student;
    ListNode *next;
} ListNode;

typedef struct List
{
    ListNode *first;
} List;

void insertIntoList(List *list, Student *newStudent);
Student *searchList(List *list, int index);
void deleteFromList(List *list, int index);

void insertIntoList(List *list, Student *newStudent)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));

    newNode->student = *newStudent;

    if (list->first == NULL)
    {
        list->first = newNode;
        return;
    } 

    ListNode *prev = list->first;

    while (prev->next != NULL) prev = prev->next;
    
    prev->next = newNode;

    return;
}

Student *searchList(List *list, int index)
{
    if(list->first == NULL)
    {
        return NULL;
    }

    ListNode *currentNode = list->first;

    while(1)
    {
        if (currentNode->student.index == index)
        {
            return &currentNode->student;
        }

        if(currentNode->next == NULL){
            break;
        }

        currentNode = currentNode->next;        
    }
       

    return NULL;
}

void deleteFromList(List *list, int index)
{
    if (list->first == NULL)
    {
        return;
    }

    ListNode *currentNode = list->first, *previousNode;

    if (currentNode->student.index == index)
    {
        list->first = currentNode->next;
        free(currentNode);
        return;
    }
    
    while (currentNode != NULL && currentNode->student.index != index)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) return;

    previousNode->next = currentNode->next;

    free(currentNode);

    return;
}

#endif