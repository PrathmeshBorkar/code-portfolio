#include <iostream>
using namespace std;

int main()
{
    int i, j, n = 0;
    cout<<"Enter number of rows : ";
    cin>>n;
    char k[] = {'A','B','C','D','E','F','G','H','I','F','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i+1; j++)
        {
            cout<<k[i];     //only works this 25 index
        }
        cout<<endl;
    }
    return 0;
}