#include<iostream>
#include <string>
using namespace std;
int M=0;
int main()
{
    cin>>M;
    string login,logout;
    string min_in="25:00:00";
    string max_out="-10:00:00";
    for(int i=0;i<M;i++)
    {
        string id,in_time,out_time;
        cin>>id>>in_time>>out_time;
        if(in_time<min_in)
        {
            min_in=in_time;
            login=id;
        }
        if(out_time>max_out)
        {
            max_out=out_time;
            logout=id;
        }
    }
    cout<<login<<" "<<logout;
    return 0;
}