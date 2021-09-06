#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
const int maxn = 100000;
using namespace std;
struct node
{
    int add, next, data;
};
vector<node> mylist(maxn);
int main()
{
    int n, begin;
    cin >> n >> begin;
    for (int i = 0; i < n; i++)
    {
        int address;
        cin >> address;
        scanf("%d%d", &mylist[address].data, &mylist[address].next);
        mylist[address].add = address;
    }
    int p = begin;
    vector<node> res;
    while (p != -1)
    {
        res.emplace_back(mylist[p]);
        p = mylist[p].next;
    }
    n = res.size();
    // dont have a useful node
    if(n == 0)
    {
        printf("0 -1");
        return 0;
    }
    sort(res.begin(), res.end(), [](node &a, node &b)
         { return a.data < b.data; });
    printf("%d %05d\n", n, res[0].add);
    if (n != 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            printf("%05d %d %05d\n", res[i].add, res[i].data, res[i + 1].add);
        }
    }
    printf("%05d %d -1", res[n - 1].add, res[n - 1].data);
    return 0;
}