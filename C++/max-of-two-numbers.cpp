#include <iostream>
using namespace std;

class Number
{
    int a, b;

public:
    void accept()
    {
        cout << "Enter two numbers: ";
        cin >> a >> b;
    }

    int findMax()
    {
        int max;
        if (a > b)
        {
            max = a;
        }
        else
        {
            max = b;
        }
        return max;
    }

    void display()
    {
        cout << "Maximum number is: " << findMax() << endl;
    }
};

int main()
{
    Number obj;
    obj.accept();
    obj.display();

    return 0;
}
