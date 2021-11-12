#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char,int> cmap;
string s1,s2;
int main()
{
    getline(cin,s1);
    getline(cin,s2);
    for(auto c:s2)
    {
        cmap[c]=1;
    }
    for(auto c:s1)
    {
        if(cmap.count(c)==0)
        {
            cout<<c;
        }
    }
    return 0;
}