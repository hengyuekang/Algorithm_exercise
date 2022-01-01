#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
    vector<int> v={1,5,2,6,9,7};
    make_heap(v.begin(), v.end());
    int cnt=v.size();
    int b=0;
    queue<int> q;
    q.emplace(b);
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        cout<<v[curr]<<endl;
        if(2*curr+1<cnt)q.emplace(2*curr+1);
        if(2*curr+2<cnt)q.emplace(2*curr+2);
    }
    return 0;
}