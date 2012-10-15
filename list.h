#ifndef LIST_H
#define LIST_H
#include <row.h>

class List
{
public:
    List();
    List(int newMaxLength);

    int maxLength;
    int length;
    Row *source;

    int maxRelease();

    List* Search(Row *value, bool equal = true);

    const char* Add(Row *value, bool recalculateRelease = true);

    const char* Delete( Row *rowSearch );

    const char* Delete( int key );

    const char* Delete( int key, int release );

    void Sort();

    const char* Print();

    const char* Clear();
};

#endif // LIST_H
