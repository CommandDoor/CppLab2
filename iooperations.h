#ifndef IOOPERATIONS_H
#define IOOPERATIONS_H
#include <iostream>

class ioOperations
{
public:
    ioOperations();

    static std::istream& input(char *& ptr);
    static std::istream& input (int &a);
    static int inputNatural();
};

#endif // IOOPERATIONS_H
