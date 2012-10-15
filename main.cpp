#include <string.h>
#include <conio.h>
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
};

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
};

///////////////////
// Structs
///////////////////
struct Item
{
       protected:
           char* info;
           int infoLength;

       public:
           int key;
           int release;

           void setInfo(char* value)
           {
                info = value;
                infoLength = strlen(info);
           };

           char* getInfo()
           {
                return info;
           };


           Item()
           {
                key = 0;
                release = 0;
                info = NULL;
           };

           Item( int newKey )
           {
                key = newKey;
                release = 0;
                setInfo(NULL);
           };

           Item( int newKey, int newRelease)
           {
                key = newKey;
                release = newRelease;
                setInfo(NULL);
           };

           Item( int newKey, int newRelease, char* newInfo)
           {
                key = newKey;
                release = newRelease;
                setInfo(newInfo);
           };

           void Clear()
           {
                delete [] info;
           }
};

struct List
{
       int maxLength;
       int length;
       Item *source;

       int maxRelease()
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

       List()
       {
             maxLength = 0;
             length = 0;
             source = new Item[0];
       }

       List(int newMaxLength)
       {
            maxLength = newMaxLength;
            length = 0;
            source = new Item[newMaxLength];
       }

       List* Search(Item *value, bool equal=true)
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

       const char* Add(Item *value, bool recalculateRelease = true)
       {
            if (length == maxLength)
               return "Maximum reached!";

            if (Search(value)->length > 0)
               return "Item is already consists!";

            source[length] = *value;
            length++;

            Sort();

            return "";
       }


       const char* Delete( Item *itemSearch )
       {
            List* excludedList = Search(itemSearch, false);

            if (excludedList->length == length)
               return "No elements found!";

            source = excludedList->source;
            length = excludedList->length;

            Sort();

            return "";
       }


       const char* Delete( int key )
       {
            return Delete(new Item(key));
       }


       const char* Delete( int key, int release )
       {
            return Delete(new Item(key, release));
       }

       void Sort()
       {
            if (length < 2) return;
            Item tmp;

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

       const char* Print()
       {
            cout<<"Key"<<"\t"<<"Release"<<"\t"<<"Information"<<endl;
            for (int i = 0; i < length; i++)
            {
                cout<<source[i].key<<"\t"<<source[i].release<<"\t"<<source[i].getInfo()<<endl;
            }

            return "";
       }

       const char* Clear()
       {
            for (int i = 0; i < length; i++)
            {
                source[i].Clear();
            }

            length = 0;

            return "";
       }
};
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

    Item *newItem = new Item();

    cout<< "Enter key: ";
    input(key);
    newItem->key = key;

    newItem->release = list->Search(newItem)->maxRelease() + 1;
    cout<< "Release would be: "<< newItem->release<< endl;

    cout<< "Enter info: ";
    input(info);
    //cin >> info;
    newItem->setInfo(info);

    return (list->Add(newItem));
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

