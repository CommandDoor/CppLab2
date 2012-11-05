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

    const char* operator+=(Row *value );

    const char* operator-=( int key );

    ostream operator<<(List *list);

    Row* operator()(Row *value);

    void Sort();

    const char* Print();

    const char* Clear();
};

#endif // LIST_H
