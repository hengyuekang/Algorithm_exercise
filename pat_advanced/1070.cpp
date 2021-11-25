#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,D;
// all are positive numbers,not always integers!
using pid=pair<double,double>;
int main()
{
    cin>>N>>D;
    vector<pid> mooncake(N);
    for(int i=0;i<N;i++) cin>>mooncake[i].first;
    for(int i=0;i<N;i++) cin>>mooncake[i].second;
    sort(mooncake.begin(),mooncake.end(),[](pid &a,pid &b){return (a.second/a.first)>(b.second/b.first);});
    double res=0.0;
    for(auto m:mooncake)
    {
        if(D>=m.first)
        {
            res+=(m.second);
            D-=m.first;
        }
        else
        {
            res=res+D*(m.second/m.first);
            break;
        }
        
    }
    printf("%.2f",res);

    return 0;
}