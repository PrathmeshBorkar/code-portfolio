#include <iostream>
using namespace std;

int main()
{
    int i, j, k, n = 0;
    cout<<"Enter number of rows : ";
    cin>>n;
    for(i = 0; i < n; i++)
    {
        j = n-i-1;
        while(j>0)
        {
            cout<<" ";
            j--;
        }
        k = 2*i + 1;
        while(k>0)
        {
            cout<<"*";
            k--;
        }
        cout<<endl;
    }
    for(i = 4; i >= 0; i--)
    {
        j = n-i-1;
        while(j>0)
        {
            cout<<" ";
            j--;
        }
        k = 2*i + 1;
        while(k>0)
        {
            cout<<"*";
            k--;
        }
        cout<<endl;
    }
    return 0;
}