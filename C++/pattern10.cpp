#include <iostream>
using namespace std;

int main()
{
    int i, j, n = 0;
    cout<<"Enter number of rows : ";
    cin>>n;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i+1; j++)
        {
            cout << "*";
        }
        cout<<endl;
        
        for(j = n-i-1; j > 0; j--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}