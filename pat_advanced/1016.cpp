#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int price[24] = {0};
int N = 0;
map<string, vector<vector<string>>> name_record;
struct SingBill
{
    string begin, end;
    int time;
    double money;
};
map<string,vector<SingBill> > bill;
int main()
{
    for (int i = 0; i < 24; i++)
    {
        scanf("%d", &price[i]);
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string name, date, state;
        cin >> name;
        if (name_record.count(name) == 0)
        {
            name_record[name].resize(2);
        }
        if (state[1] == 'n')
        {
            name_record[name][0].emplace_back(date);
        }
        else
        {
            name_record[name][1].emplace_back(date);
        }
    }
    for(auto record:name_record)
    {
        sort(record.second[0].begin(),record.second[0].end());
        sort(record.second[1].begin(),record.second[1].end());
        int i=0;
        while(i<record.second[0].size()&&i<record.second[1].size())
        {
            
            i++;
        }
    }

    return 0;
}