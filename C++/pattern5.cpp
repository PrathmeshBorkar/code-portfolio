#include <iostream>
using namespace std;

int main()
{
    int i, j, n = 0;
    cout<<"Enter number of rows : ";
    cin>>n;
    for(i = 0; i < n; i++)
    {
        for(j = n-i; j > 0; j--)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    return 0;
}