#include <string.h>
#include <conio.h>
#include <iostream>
#include "list.h"
#include <row.h>

using namespace std;


int List::maxRelease()
{
    int returnValue = -1;

    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            returnValue = source[i].release;
        }else
        {
            if (returnValue < source[i].release) returnValue = source[i].release;
        }
    }

    return returnValue;
}

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

List* List::Search(Row *value, bool equal)
{
    List *returnValue = new List(maxLength);

    for (int i = 0; i < length; i++)
    {
        if (equal)
        {
            if (source[i].key == value->key)
            {
                if (value->release > 0)
                {
                    if (source[i].release == value->release) returnValue->Add(&source[i]);
                }else
                {
                    returnValue->Add(&source[i]);
                }
            }
        }else
        {
            if (source[i].key != value->key)
            {
                returnValue->Add(&source[i]);
            } else
            {
                if (value->release > 0 && source[i].release != value->release)
                    returnValue->Add(&source[i]);
            }
        }
    }

    return returnValue;
}

const char* List::Add(Row *value, bool recalculateRelease)
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


const char* List::Delete( Row *rowSearch )
{
    List* excludedList = Search(rowSearch, false);

    if (excludedList->length == length)
        return "No elements found!";

    source = excludedList->source;
    length = excludedList->length;

    Sort();

    return "";
}


const char* List::Delete( int key )
{
    return Delete(new Row(key));
}


const char* List::Delete( int key, int release )
{
    return Delete(new Row(key, release));
}

void List::Sort()
{
    if (length < 2) return;
    Row tmp;

    for (int i = 0; i < length-1; i++)
    {
        if (source[i].key > source[i+1].key)
        {
            tmp = source[i];
            source[i] = source[i+1];
            source[i+1] = tmp;
        }
    }
}

const char* List::Print()
{
    cout<<"Key"<<"\t"<<"Release"<<"\t"<<"Information"<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<source[i].key<<"\t"<<source[i].release<<"\t"<<source[i].getInfo()<<endl;
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
