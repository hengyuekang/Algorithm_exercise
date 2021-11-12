#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N, K;
struct Peo
{
    string name;
    int age, money;
};
// valid:same size as peo,store max 100 at every age(at most 100 per age)
vector<Peo> peo,valid;
bool cmp(Peo &a, Peo &b)
{
    if (a.money != b.money)
        return a.money > b.money;
    else if (a.age != b.age)
        return a.age < b.age;
    else
        return a.name < b.name;
}
int main()
{
    cin >> N >> K;
    peo.resize(N);
    valid.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> peo[i].name >> peo[i].age >> peo[i].money;
    }
    // sort once,same standard,get different age arange
    sort(peo.begin(), peo.end(), cmp);
    vector<int> Age(2000,0);
    // preprocess
    // at most valid count
    int validcount=0;
    for(int i=0;i<N;i++)
    {
        // one age,100 most
        if(Age[peo[i].age]<100)
        {
            Age[peo[i].age]++;
            valid[validcount++]=peo[i];
        }
    }
    for (int i = 0; i < K; i++)
    {
        int num, amin, amax;
        cin >> num >> amin >> amax;
        cout << "Case #" << i + 1 << ":\n";
        int printcnt=0;
        for(int j=0;j<validcount&&printcnt<num;j++)
        {
            if(valid[j].age>=amin &&valid[j].age<=amax)
            {
                cout<<valid[j].name<<" "<<valid[j].age<<" "<<valid[j].money<<endl;
                printcnt++;
            }
        }
        if(printcnt==0)
        {
            cout<<"None\n";
        }
    }

    return 0;
}