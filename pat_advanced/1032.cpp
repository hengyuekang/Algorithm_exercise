#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
const int maxn=100000;
// next,flag(whether belong to the first list)
vector<pair<int,int>> nodes(maxn);
int main()
{
    int begin1,begin2,n;
    cin>>begin1>>begin2>>n;
    for(auto &n:nodes)
    {
        n.second=0;
    }
    if(begin1==begin2)
    {
        printf("%05d",begin1);
        return 0;
    }
        for(int i=0;i<n;i++)
        {
            int add,next;
            char c;
            cin>>add>>c>>next;
            nodes[add].first=next;
            // similarly,we dont know whether the nodes put are of one of the list until iteration
        }
    int p=begin1;
    while(p!=-1)
    {
        nodes[p].second=1;
        p=nodes[p].first;
    }
    p=begin2;
    while(p!=-1)
    {
        if(nodes[p].second==1)
        {
            printf("%05d",p);
            return 0;
        }
        p=nodes[p].first;
    }
    cout<<"-1";
    return 0;
}