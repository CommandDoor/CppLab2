#include "row.h"
#include <string.h>
#include <conio.h>
#include <iostream>
#include <ioOperations.h>
using namespace std;

#include <stdlib.h>

Row::Row()
{
    isOccupied = 0;
    key = 0;
    info = NULL;
}

Row::~Row()
{
    delete [] info;
}

ostream& operator <<(ostream &out, Row *row)
{
    if (row->isOccupied == 1)
        out<<row->isOccupied<<"\t"<<row->key<<"\t"<<row->info<<endl;
    else
        out<<"0\t0"<<endl;
    return out;
}

istream& operator >>(istream &in, Row *&row)
{
    cout<< "Enter key: ";
    ioOperations::input(row->key);

    cout<< "Enter info: ";
    ioOperations::input(row->info);

    return in;
}
