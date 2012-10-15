#include <string.h>
#include <conio.h>
#include <row.h>
#include <list.h>
#include <iostream>

using namespace std;

const int maxSize = 10;
FILE *f;
char* file;

///////////////////
// Input operations
///////////////////
istream &input(char *& ptr){
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

istream &input (int &a)
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

int inputNatural()
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

///////////////////
// Menu operations
///////////////////
int Menu ()
{
    int c;
    cout<< "1.Add new record."<<endl<<"2.Delete record."<<endl<<"3.Clear table."<<endl<<"4.Print table."<<endl<<"5.Exit."<<endl;
    input(c);
    while (c<=0 || c>5) {
        cout<< "Uncorrect! Reenter: ";
        input(c);
    }
    return c;
}

const char* AddMenuClick(List *list)
{
    int key, release;
    char *info;

    Row *newRow = new Row();

    cout<< "Enter key: ";
    input(key);
    newRow->key = key;

    newRow->release = list->Search(newRow)->maxRelease() + 1;
    cout<< "Release would be: "<< newRow->release<< endl;

    cout<< "Enter info: ";
    input(info);
    //cin >> info;
    newRow->setInfo(info);

    return (list->Add(newRow));
}

const char* DeleteMenuClick(List *list)
{
    int key, release;
    cout<< "Enter key: ";
    input(key);
    cout<< "Enter release: ";
    input(release);
    if (release > 0)
    {
       return (list->Delete(key, release));
    }else
    {
       return (list->Delete(key));
    }
}

const char* ClearMenuClick(List *list) //пункт 3
{
    return (list->Clear());
}

const char* PrintMenuClick(List *list) //пункт 4
{
    return (list->Print());
}

///////////////////
// Main
///////////////////
int main(int argc, char *argv[])
{
    List *list = new List(maxSize);

    bool b = true;
    while (b) {
        //system ("cls");
        int c = Menu ();
        const char* result;
        switch (c) {
            case 1: result = AddMenuClick(list);
                    break;
            case 2: result = DeleteMenuClick(list);
                    break;
            case 3: result = ClearMenuClick(list);
                    break;
            case 4: result = PrintMenuClick(list);
                    break;
            case 5: b = false;
                    break;
        }

        if (b)
        {
            const char* message = result == "" ? "Success!" : result;
            cout<<endl<<message<<endl;
            _getch();
        }
    }

    list->Clear();

    return 0;
}

