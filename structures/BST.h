#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <stdlib.h>
#include "Student.h"

typedef struct BSTNode
{
    Student student;
    struct BSTNode *left, *right;
} BSTNode;

BSTNode *insertIntoTree(BSTNode *node, Student *newStudent);
Student *searchTree(BSTNode *node, int index);
BSTNode *getMinNode(BSTNode *node);
BSTNode *deleteFromTree(BSTNode *node, int index);

BSTNode *insertIntoTree(BSTNode *node, Student *newStudent)
{
    if (node == NULL)
    {
        BSTNode *newNode = (BSTNode *)calloc(1, sizeof(BSTNode));
        newNode->student = *newStudent;
        return newNode;
    }

    if (node->student.index < newStudent->index)
        node->right = insertIntoTree(node->right, newStudent);
    else
        node->left = insertIntoTree(node->left, newStudent);
        
    return node;
}

Student *searchTree(BSTNode *node, int index)
{
    if (node == NULL)
        return NULL;

    if (node->student.index == index)
        return &node->student;

    if (node->student.index < index)
        return searchTree(node->right, index);
    else
        return searchTree(node->left, index);
}

BSTNode *getMinNode(BSTNode *node)
{
    BSTNode *currentNode = node;

    while (currentNode->left != NULL)
    {
        currentNode = currentNode->left;
    }
    
    return currentNode;
}

BSTNode *deleteFromTree(BSTNode *node, int index)
{
    if (node == NULL)
        return NULL;

    if (node->student.index < index)
        node->right = deleteFromTree(node->right, index);
    else if (node->student.index > index)
        node->left = deleteFromTree(node->left, index);
    else
    {

        if (node->left == NULL)
        {
            BSTNode *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            BSTNode *temp = node->left;
            free(node);
            return temp;
        }

        BSTNode *minNode = getMinNode(node->right);

        node->student = minNode->student;

        node->right = deleteFromTree(node->right, minNode->student.index);
    }

    return node;
}

#endif