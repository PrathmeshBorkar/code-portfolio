#include <iostream>
using namespace std;

int main()
{
    int i, j, n = 0;
    cout<<"Enter number of rows : ";
    cin>>n;
    int k = 1;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i+1; j++)
        {
            cout<<k<<" ";
            k++;
        }
        cout<<endl;
    }
    return 0;
}