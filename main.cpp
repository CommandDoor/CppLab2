#include <windows.h>

#include <string.h>
#include <conio.h>
#include <row.h>
#include <list.h>
#include <iostream>
#include <ioOperations.h>

using namespace std;

const int maxSize = 10;

///////////////////
// Menu operations
///////////////////
int Menu ()
{
    int c;
    cout<<"1.Add new record."<<endl;
    cout<<"2.Delete record."<<endl;
    cout<<"3.Search record."<<endl;
    cout<<"4.Clear table."<<endl;
    cout<<"5.Print table."<<endl;
    cout<<"6.Exit."<<endl;
    ioOperations::input(c);

    while (c<=0 || c>6)
    {
        cout<< "Uncorrect! Reenter: ";
        ioOperations::input(c);
    }

    return c;
}

const char* AddMenuClick(List *list)
{
    Row* newRow = new Row();
    cin>>newRow;
    cout<<newRow;

//    list->source[0] = *newRow;
//    list->length = 1;
//    cout<<*list;
    return (*list+=newRow);
}

const char* DeleteMenuClick(List *list)
{
    int key;
    cout<< "Enter key: ";
    ioOperations::input(key);
    return (*list-=key);
}

void ClearMenuClick(List *list)
{
    list->~List();
}

void SearchMenuClick(List *list)
{
    int key;
    cout<< "Enter key: ";
    ioOperations::input(key);
    Row* searchRow = list->operator ()("key", key);
    if (searchRow == NULL)
        cout<<"No items found!";
    else
        cout<<searchRow;

    cout<<endl;
}

void PrintMenuClick(List *list)
{
    cout<<*list;
}

///////////////////
// Main
///////////////////
int main(int argc, char *argv[])
{
    try
    {
        List *list = new List(maxSize);

        bool b = true;
        while (b) {
            cout<<"==============================="<<endl;
            system ("cls");
            int c = Menu ();
            b = true;
            const char* result;
            switch (c)
            {
                case 1: result = AddMenuClick(list);
                    break;
                case 2: result = DeleteMenuClick(list);
                    break;
                case 3: SearchMenuClick(list);
                    break;
                case 4: ClearMenuClick(list);
                    break;
                case 5: PrintMenuClick(list);
                    break;
                case 6: b = false;
                    break;
            }

            if (b)
            {
                const char* message = !(bool)*result ? "Success!" : result;
                cout<<message<<endl;
                _getch();
            }
        }

        list->~List();
    }
    catch(...)
    {
        cout<<"Error occured!"<<endl;
    }

    return 0;
}

