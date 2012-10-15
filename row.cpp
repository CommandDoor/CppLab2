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
    release = 0;
    info = NULL;
}

Row::Row( int newKey )
{
    key = newKey;
    release = 0;
    setInfo(NULL);
}

Row::Row( int newKey, int newRelease)
{
    key = newKey;
    release = newRelease;
    setInfo(NULL);
}

Row::Row( int newKey, int newRelease, char* newInfo)
{
    key = newKey;
    release = newRelease;
    setInfo(newInfo);
}

void Row::Clear()
{
    delete [] info;
}
