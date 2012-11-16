#ifndef LIST_H
#define LIST_H
#include <row.h>
#include <iostream>
#include <conio.h>

class List
{
public:

    int maxLength;
    int length;
    Row *source;

    List();
    List(int newMaxLength);
    ~List();

    const char* operator+=(Row *value );

    const char* operator-=( int key );

    Row* operator()(const char* propertyName, int value);

    friend std::ostream& operator<<(std::ostream &out, List &list);
};

#endif // LIST_H
