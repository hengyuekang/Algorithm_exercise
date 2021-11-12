#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N,K;
struct Stu
{
    string id;
    int score=0,fr=1,ln=1,lk=1;
};
vector<vector<Stu>> stu;
bool cmp(Stu &s1,Stu &s2)
{
    if(s1.score!=s2.score) return s1.score > s2.score;
    else return s1.id<s2.id;
}
int main()
{
    cin>>N;
    stu.resize(N);
    int sum=0;
    for(int i=0;i<N;i++)
    {
        cin>>K;
        stu[i].resize(K);
        sum+=K;
        for(int j=0;j<K;j++)
        {
            cin>>stu[i][j].id>>stu[i][j].score;
            stu[i][j].ln=i+1;
        }
        sort(stu[i].begin(),stu[i].end(),cmp);
        stu[i][0].lk=1;
        for(int m=1;m<stu[i].size();m++)
        {
            if(stu[i][m].score==stu[i][m-1].score)
            {
                stu[i][m].lk=stu[i][m-1].lk;
            }
            else
            {
                stu[i][m].lk=m+1;
            }
        }
    }
    vector<Stu> res;
    for(auto vs:stu)
    {
        for(auto s:vs)
        {
            res.emplace_back(s);
        }
    }
    sort(res.begin(),res.end(),cmp);
    res[0].fr=1;
    for(int i=1;i<res.size();i++)
    {
        if(res[i].score==res[i-1].score)
        {
            res[i].fr=res[i-1].fr;
        }
        else
        {
            res[i].fr=i+1;
        }
    }
    cout<<res.size()<<endl;
    for(auto s:res)
    {
        cout<<s.id<<" "<<s.fr<<" "<<s.ln<<" "<<s.lk<<"\n";
    }
    return 0;
}