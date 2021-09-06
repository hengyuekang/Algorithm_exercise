#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
int n,p,k;
vector<int> fac;
vector<int> temp,ans;
int maxfacsum=-1;
void DFS(int index,int nowk,int sum,int facsum)
{
    if((nowk==k)&&(sum==n))
    {
        if(facsum>maxfacsum)
        {
            maxfacsum=facsum;
            ans=temp;
        }
        return;
    }
    else if((nowk>k)||(sum>n)||(index<1))
    {
        return;
    }
    else
    {
        // choose index
        temp.emplace_back(index);
        DFS(index,nowk+1,sum+fac[index],facsum+index);
        // not choose
        temp.pop_back();
        DFS(index-1,nowk,sum,facsum);
    }
}
int main()
{
    cin>>n>>k>>p;
    for(int i=0;(pow(i,p)<=n);i++)
    {
        fac.emplace_back(pow(i,p));
    }
    DFS(fac.size()-1,0,0,0);
    if(maxfacsum!=-1)
    {
        cout<<n<<" = "<<ans[0]<<"^"<<p;
        for(int i=1;i<ans.size();i++)
        {
            cout<<" + "<<ans[i]<<"^"<<p;
        }
    }
    else
    {
        cout<<"Impossible";
    }
    return 0;
}