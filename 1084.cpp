#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cstdlib>
using namespace std;
string in, out;
map<char,int> outmap;
vector<char> res;
int main()
{
    int diff='A'-'a';
    cin >> in >> out;
    for(auto c:out) {
        if(outmap.count(c)==0)
        {
            outmap[c]=1;
        }
    }
    for(auto c:in) {
        if(outmap.count(c)==0)
        {
            if(isalpha(c))
            {
                if(c>='a' && c<='z')
                {
                    c=toupper(c);
                }
            }
            if(find(res.begin(),res.end(),c)==res.end())
            {
                res.emplace_back(c);
            }
        }

    }
    for(auto c:res)
    {
        cout<<c;
    }
    return 0;
}