#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> d2s={"zero", "one", "two", "three", "four", "five","six", "seven", "eight", "nine"};
int main()
{
    string str;
    cin>>str;
    string sres;
    int ires=0;
    for(auto s:str)
    {
        ires+=s-'0';
    }
    sres=to_string(ires);
    cout<<d2s[sres[0]-'0'];
    for(int i=1;i<sres.size();++i)
    {
        cout<<" "<<d2s[sres[i]-'0'];
    }
    return 0;
}