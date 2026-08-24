#include <iostream>
using namespace std;

int main()
{
    int i, j, n = 0;
    cout<<"Enter number of rows : ";
    cin>>n;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            cout<<j+1;
        }
        for(j = 0; j <= 2*(n-i-1); j++)
        {
            cout<<" ";
        }
        for(j = i; j >= 0; j--)
        {
            cout<<j+1;
        }
        cout<<endl;
    }
    return 0;
}