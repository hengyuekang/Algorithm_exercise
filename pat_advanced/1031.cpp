#include <iostream>
#include <string>
using namespace std;
string str;
int main()
{
    cin>>str;
    int N=str.size();
    int n1=(N+2)/3;
    int n2=(N+2)-2*n1;
    for(int i=0; i<n1-1; i++)
    {
        cout<<str[i];
        for(int j=0; j<n2-2; j++)
        {
            cout<<" ";
        }
        cout<<str[N-1-i]<<"\n";
    }
    for(int i=0; i<n2; i++)
    {
        cout<<str[n1-1+i];
    }
    return 0;
}