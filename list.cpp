#include <string.h>
#include <conio.h>
#include <iostream>
#include "list.h"
#include "row.h"

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
    for (int i = 0; i < maxLength; i++)
        source[i] = *(new Row());
}

List::~List()
{
    for (int i = 0; i < maxLength; i++)
        source[i].~Row();

    length = 0;
}

const char* List::operator+=(Row *value )
{
    if (length == maxLength)
        return "Maximum reached!";

    if (operator()((const char*)"key", value->key)!= NULL)
    {
        return "Row is already consists!";
    }
    else if ( length < maxLength )
    {
        Row* searchRow = operator ()((const char*)"isOccupied", 0);
        searchRow->isOccupied = 1;
        searchRow->key = value->key;
        searchRow->info = value->info;
        length++;
    }
    else
    {
    }

    return "";
}

const char* List::operator-=( int key )
{
    Row* searchRow = operator()((const char*)"key", key);
    if (searchRow == NULL)
        return "No elements found";

    //Удаляем и записываем на его место последний элемент.
//    searchRow->key = source[length-1].key;
//    searchRow->info = source[length-1].info;
//    source[length-1].isOccupied = 0;

    searchRow->isOccupied = 0;
    length--;
    return "";
}

Row* List::operator()(const char* propertyName, int value)
{
    for (int i = 0; i < maxLength; i++)
    {
        if (*propertyName == *(const char*)"key")
            if (source[i].key == value) return &source[i];
        if (*propertyName == *(const char*)"isOccupied")
            if (source[i].isOccupied == value) return &source[i];

    }
    return NULL;
}

ostream& operator<<(ostream &out, List &list)
{
    out<<"isBusy"<<"\t"<<"Key"<<"\t"<<"Information"<<endl;
    for (int i = 0; i < list.maxLength; i++)
        out<<&list.source[i];

    return out;
}
