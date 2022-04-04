#ifndef ORDERED_LIST
#define ORDERED_LIST

struct ListElement
{
    char firstname[12];
    char lastname[12];
    int index;
    struct ListElement *next;
};


struct ListHead
{
    struct ListElement *first;
};


#endif