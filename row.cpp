#include "row.h"
#include <string.h>
#include <conio.h>

using namespace std;

void Row::setInfo(char* value)
{
    info = value;
    infoLength = strlen(info);
}

char* Row::getInfo()
{
    return info;
}


Row::Row()
{
    key = 0;
    info = NULL;
}

Row::Row( int newKey )
{
    key = newKey;
    setInfo(NULL);
}

Row::Row( int newKey, char* newInfo)
{
    key = newKey;
    setInfo(newInfo);
}

void Row::Clear()
{
    delete [] info;
}
