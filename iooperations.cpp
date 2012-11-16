#include "iooperations.h"
#include <iostream>
#include <string.h>

using namespace std;

ioOperations::ioOperations()
{
}

istream& ioOperations::input(char *& ptr)
{
    ptr = new char[1];
    *ptr = '\0';
    int l = 0;
    char buf[80];
    //  cout<< "enter string or EOF, for end programm"<<endl;
    do{
        cin.clear();
        cin.getline(buf,80);
        if(cin.eof()){;break;}
        l+=strlen(buf);
        char * prev = ptr;
        ptr = new char[l+1];
        strcpy(ptr,prev);
        strcat(ptr,buf);
        delete[]prev;
    } while (cin.fail());
    return cin;
}

istream& ioOperations::input (int &a)
{
    while(!(cin>>a))
    {
        if(cin.eof()) break;
        cin.clear();
        cin.ignore();
    };

    cin.ignore();
    return cin;
}

int ioOperations::inputNatural()
{
    int n;
    const char* errorString = "";
    do{
        cout<<errorString;
        errorString="Please, try again.\n";
        input(n);
    }while (n<=0);

    return n;
}

