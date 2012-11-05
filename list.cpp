#include <string.h>
#include <conio.h>
#include <iostream>
#include "list.h"
#include <row.h>

using namespace std;


List::List()
{
    maxLength = 0;
    length = 0;
    source = new Row[0];
}

List::List(int newMaxLength)
{
    maxLength = newMaxLength;
    length = 0;
    source = new Row[newMaxLength];
}

Row* List::operator()(Row *value)
{
    for (int i = 0; i < length; i++)
    {
        if (source[i].key == value->key) return &source[i];
    }

    return NULL;
}

const char* List::operator+=(Row *value )
{
    if (length == maxLength)
        return "Maximum reached!";

    if (Search(value)->length > 0)
        return "Row is already consists!";

    source[length] = *value;
    length++;

    Sort();

    return "";
}

const char* List::operator-=( int key )
{
    return "Delete(new Row(key))";
}

ostream List::operator <<(List *list)
{
    cout<<"Key"<<"\t"<<"\t"<<"Information"<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<source[i].key<<"\t"<<"\t"<<source[i].getInfo()<<endl;
    }

    return "";
}

const char* List::Clear()
{
    for (int i = 0; i < length; i++)
    {
        source[i].Clear();
    }

    length = 0;

    return "";
}
