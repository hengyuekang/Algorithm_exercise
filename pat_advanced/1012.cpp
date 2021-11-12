#include<iostream>
#include<cstdio>
#include<algorithm>
#include<numeric>
using namespace std;
int N,M;
struct Stu
{
    int id=0,grade[4]={0};
} stu[2010];
int Rank[1000000][4]={0};
// specify to sort which course
int now;
char symbol[4]={'A','C','M','E'};
bool cmp(Stu &a, Stu &b)
{ return a.grade[now]>b.grade[now];}
int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d%d",&stu[i].id,&stu[i].grade[1],&stu[i].grade[2],&stu[i].grade[3]);
        stu[i].grade[0]=accumulate(stu[i].grade+1,stu[i].grade+4,0)/3;
    }
    for(int i=0;i<4; i++)
    {
        now=i;
        sort(stu,stu+N,cmp);
        Rank[stu[0].id][now]=1;
        for(int i=1;i<N;i++)
        {
            if(stu[i].grade[now]==stu[i-1].grade[now])
            {
                Rank[stu[i].id][now]=Rank[stu[i-1].id][now];
            }
            else
            {
                Rank[stu[i].id][now]=i+1;
            }
        }
        // some extrme examples!
        // for(int j=0;j<N-1;)
        // {
        //     if(stu[j].grade[now]==stu[j+1].grade[now])
        //     {
        //         Rank[stu[j].id][now]=Rank[stu[j+1].id][now]=curr_rank;
        //         curr_rank+=2;
        //         j+=2;
        //     }
        //     else
        //     {
        //         Rank[stu[j].id][now]=curr_rank;
        //         curr_rank++;
        //         j++;
        //     }
        // }
        // Rank[stu[N-1].id][now]=N;
    }
    int query=0;
    for(int i=0;i<M;i++)
    {
        cin>>query;
        if(Rank[query][0]==0)
        {
            cout<<"N/A\n";
        }
        else
        {
            //int res1=Rank[query][0];
            int res2=0;
            for(int j=0;j<4;j++)
            {
                if(Rank[query][j]<Rank[query][res2])
                {
                    //res1=Rank[query][j];
                    res2=j;
                }
            }
            cout<<Rank[query][res2]<<" "<<symbol[res2]<<"\n";
        }
    }
    return 0;
}