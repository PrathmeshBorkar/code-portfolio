#include<iostream>
using namespace std;

class Base
{
    public:
        int i,j;
        Base()
        {
            cout<<"Inside Base Constructor\n";
            i=0;
            j=0;
        }
        ~Base()
        {
            cout<<"Inside Base Destructor\n";
        }
        void fun()
        {
            cout<<"Inside Base fun";
        }
};

class Derived:public Base
{

};

int main()
{
    Base bobj;
    //Derived dobj;
    return 0;
}