#ifndef ORDERED_LIST
#define ORDERED_LIST



typedef struct ListNode
{
    char firstname[12];
    char lastname[12];
    int index;
    struct ListElement *next;
} ListNode;


typedef struct List
{
    ListNode *first;
} List;


#endif