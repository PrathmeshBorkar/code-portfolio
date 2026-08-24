#include <iostream>
using namespace std;

int main()
{
    int i, j, k, n = 0;
    cout<<"Enter number of rows : ";
    cin>>n;
    for(i = n-1; i >= 0; i--)
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