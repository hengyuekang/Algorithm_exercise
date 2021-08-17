#include<iostream>
#include<vector>
using namespace std;
int N,b;
vector<int> num;
bool isPali()
{
    for(int i=0;i<num.size()/2;i++)
    {
        if(num[i]!=num[num.size()-1-i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin>>N>>b;
    while(N!=0)
    {
        num.emplace_back(N%b);
        N/=b;
    }
    if(isPali())
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    for(int i=num.size()-1;i>=0;i--)
    {
        cout<<num[i];
        if(i!=0)
        {
            cout<<" ";
        }
    }
    return 0;
}