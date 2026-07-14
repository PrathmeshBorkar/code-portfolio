#include <iostream>
using namespace std;

int main()
{
    //We can create one reference to one variable
    int no = 11;
    int &x = no;

    //We can multiple references for single variable
    int &y = no;

    //We can create reference to reference
    int &z = y;

    //We can create reference to pointer
    int *p = &no;
    int *(&q) = p;      //so basically 'q' also points to 'no'

    return 0;
}