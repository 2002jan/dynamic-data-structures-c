#include "StudentsLoader.h"

int main()
{
    initStudetsList(1000000);

    free(Students);

    return 0;
}