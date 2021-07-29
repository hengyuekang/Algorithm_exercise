#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int M=0;
int N=0;
vector<int> D={0};
vector<int> startDis={0,0};
vector<pair<int,int> > exits={{0,0}};
int main()
{
    int sum=0;
    scanf("%d",&N);
    for(int i=2;i<N+2;i++)
    {
        int dis=0;
        scanf("%d",&dis);
        sum+=dis;
        startDis.emplace_back(startDis[i-1]+dis);
        D.emplace_back(dis);
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        pair<int,int> tmp;
        scanf("%d%d",&tmp.first,&tmp.second);
        if(tmp.first>tmp.second)
        {
            swap(tmp.first,tmp.second);
        }
        exits.emplace_back(tmp);
    }

    for(int i=1;i<=M;i++)
    {
        int res=0;
        int tmpdis=startDis[exits[i].second]-startDis[exits[i].first];
        res=min(tmpdis,sum-tmpdis);
        printf("%d",res);
        if(i!=M)
        {
            printf("\n");
        }
    }

    return 0;
}
// distance:difference from a same standard,which can be taken down when inputting
// turnover:sum-current