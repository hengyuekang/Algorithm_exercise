#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<pair<int,float>> A;
vector<pair<int,float>> B;
int size_a=0;
int size_b=0;
int main()
{
    scanf("%d",&size_a);
    for(int i=0; i<size_a;i++)
    {
        pair<int,float> tmp;
        scanf("%d%f",&tmp.first,&tmp.second);
        A.emplace_back(tmp);
    }

    scanf("%d",&size_b);
    for(int i=0; i<size_b;i++)
    {
        pair<int,float> tmp;
        scanf("%d%f",&tmp.first,&tmp.second);
        B.emplace_back(tmp);
    }

    map<int,float> res;
    for(auto a:A)
    {
        for(auto b:B)
        {
            if(res.find(a.first+b.first)==res.end())
            {
                res[a.first+b.first]=0;
            }
            res[a.first+b.first]+=a.second*b.second;
            if(res[a.first+b.first]==0)
            {
                res.erase(a.first+b.first);
            }
        }
    }

    vector<pair<int,float>> outres(res.begin(),res.end());
    sort(outres.begin(),outres.end(),[](pair<int,float> &p1,decltype(p1) p2){return p1.first>p2.first;});
    printf("%lu ",outres.size());
    for(int i=0;i<outres.size();i++)
    {
        printf("%d %.1f",outres[i].first,outres[i].second);
        if(i!=outres.size()-1)
        {
            printf(" ");
        }
    }

    return 0;
}
// pay attention to that coefficients of res item is 0