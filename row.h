#ifndef ROW_H
#define ROW_H
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

class Row
{

private:

protected:

public:
    int isOccupied;
    int key;
    char* info;

    Row();
    ~Row();

    friend std::ostream& operator <<(std::ostream &out, Row *row);
    friend std::istream& operator >>(std::istream &in, Row *&row);
};

#endif // ROW_H
