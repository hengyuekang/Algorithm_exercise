#include<iostream>
#include<vector>
using namespace std;
int ans[10001]={0};
vector<int> res;
int main()
{
    int N;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        int num=0;
        cin>>num;
        ans[num]++;
        res.emplace_back(num);
    }
    for(auto n:res)
    {
        if(ans[n]==1)
        {
            cout<<n;
            return 0;
        }
    }
    cout<<"None";
    return 0;
}