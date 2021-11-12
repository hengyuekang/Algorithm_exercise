#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int N,M;
int hashtable[1001]={0};
int main()
{
    cin>>N>>M;
    for(int i=0;i< N; i++)
    {
        int num=0;
        cin>>num;
        hashtable[num]++;
    }
    for(int i=0;i<1001;i++)
    {
        if(hashtable[i]>0)
        {
            if(hashtable[M-i]>0)
            {
                if((2*i==M)&&hashtable[i]<2)
                {
                    continue;
                }
                cout<<i<<" "<<M-i;
                return 0;
            }
        }
    }
    cout<<"No Solution";
    return 0;
}