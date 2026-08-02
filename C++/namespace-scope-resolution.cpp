#include <iostream>

namespace Demo
{
    int no = 11;
    void fun()
    {
        std::cout<<"fun method of Demo namespace";
    }
}

int main()
{
    std::cout<<"Jay Ganesh\n";
    Demo::fun();
    return 0;
}