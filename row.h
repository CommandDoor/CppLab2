#ifndef ROW_H
#define ROW_H

class Row
{

private:

protected:
    char* info;
    int infoLength;

public:
    int key;
    int release;

    void setInfo(char* value);

    char* getInfo();

    Row();

    Row( int newKey );

    Row( int newKey, int newRelease);

    Row( int newKey, int newRelease, char* newInfo);

    void Clear();
};

#endif // ROW_H
