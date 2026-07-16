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
            cout<<"Inside Base fun\n";
        }
};

class Derived:public Base
{
    public:
        int x;
        Derived()
        {
            cout<<"Inside Derived Constructor\n";
        }
        ~Derived()
        {
            cout<<"Inside Derived Destructor\n";
        }
        void gun()
        {
            cout<<"Inside Derived gun\n";
        }
};

int main()
{
    cout<<"Inside main\n";
    Derived dobj;
    cout<<"Size of derived class object is : "<<sizeof(Base)<<"\n";
    cout<<"Size of derived class object is : "<<sizeof(Derived)<<"\n";
    cout<<"i:"<<dobj.i<<"\nj:"<<dobj.j<<"\nx:"<<dobj.x<<"\n";
    dobj.fun();
    dobj.gun();
    cout<<"End of main\n";
    return 0;
}