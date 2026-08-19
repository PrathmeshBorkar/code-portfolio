#include <iostream>
using namespace std;

int main()
{
    int i, j, n = 0;
    cout<<"Enter number of rows : ";
    cin>>n;
    for(i = 0; i < n; i++)
    {
        for(j = 1; j < i+2; j++)
        {
            cout << j << " ";
        }
        cout<<endl;
    }
    return 0;
}