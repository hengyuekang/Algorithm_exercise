#include <iostream>
#include <cstring>
using namespace std;
int num,minNumber;
int maxTime=-1;
int counting[10010];
int main()
{
    cin>>num;
    memset(counting,0,sizeof(counting));
    for(int i=0;i<num;i++)
    {
        int tmp;
        cin>>tmp;
        counting[tmp]++;
    }
    for(int i=0;i<10010;i++)
    {
        if(counting[i]>maxTime)
        {
            maxTime=counting[i];
            minNumber=i;
        }
    }
    cout<<minNumber;
    return 0;
}