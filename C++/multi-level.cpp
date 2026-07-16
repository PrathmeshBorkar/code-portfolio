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
            x=0;
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

class DerivedX:public Derived
{
    public:
        int y;
        DerivedX()
        {
            cout<<"Inside DerivedX Constructor\n";
            y=0;
        }
        ~DerivedX()
        {
            cout<<"Inside DerivedX Destructor\n";
        }
        void sun()
        {
            cout<<"Inside DerivedX sun\n";
        }
};

int main()
{
    cout<<"Inside main\n";
    DerivedX xobj;
    cout<<"Size of base class object is : "<<sizeof(Base)<<"\n";
    cout<<"Size of derived class object is : "<<sizeof(Derived)<<"\n";
    cout<<"Size of deriveded class object is : "<<sizeof(DerivedX)<<"\n";
    cout<<"i:"<<xobj.i<<"\nj:"<<xobj.j<<"\nx:"<<xobj.x<<"\ny:"<<xobj.y<<"\n";
    xobj.fun();
    xobj.gun();
    xobj.sun();
    cout<<"End of main\n";
    return 0;
}