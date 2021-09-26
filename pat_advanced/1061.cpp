#include<iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> today{"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
vector<int> totime;
string day1,day2,time1,time2;
    cin>>day1>>day2>>time1>>time2;

    for(int i=0; i<24;i++)
    {
        totime.emplace_back(i);
    }
    int i=0;
    for(i=0;i<day1.size()&&day2.size();i++)
    {
        if((day1[i]==day2[i])&&isupper(day2[i]))
        {
            cout<<today[day2[2]-'A']<<" ";
        }
    }
    for(;i<day1.size()&&day2.size();i++)
    {
        if((day1[i]==day2[i]))
        {
            if(day2[i]>=65)
            {
                cout<<totime[day2[2]-'A'];
            }
            else
            {
                char tmp[1];
                tmp[0]=day2[i];
                cout<<totime[atoi(tmp)];
            }
            cout<<":";
        }
    }
    for(int j=0;j<time1.size()&&j<time2.size();j++)
    {
        if((day1[j]==day2[j])&&((islower(day2[j]))||(isupper(day2[j]))))
        {
            char tmp[1];
            tmp[0]=day2[j];
            int minute=atoi(tmp);
            if(minute<=9)
            {
                cout<<"0"<<minute;
            }
            else
            {
                cout<<minute;
            }
        }
    }
    return 0;
}