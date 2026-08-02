#include <iostream>

namespace Demo
{
    int no = 11;
    void fun()
    {
        std::cout<<"fun method of Demo namespace";
    }
}

using namespace Demo;

int main()
{
    std::cout<<"Jay Ganesh\n";
    fun();
    return 0;
}