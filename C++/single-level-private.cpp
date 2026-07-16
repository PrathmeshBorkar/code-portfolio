#include<iostream>
using namespace std;

class Base
{
    private:
        int i,j;
    public:
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

int main()
{
    cout<<"Inside main\n";
    Derived dobj;
    cout<<"Size of derived class object is : "<<sizeof(Base)<<"\n";
    cout<<"Size of derived class object is : "<<sizeof(Derived)<<"\n";
    //cout<<"i:"<<dobj.i<<"\nj:"<<dobj.j<<"\nx:"    //Error
    cout<<"x:"<<dobj.x<<"\n";
    cout<<"End of main\n";
    return 0;
}