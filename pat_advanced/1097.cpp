#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100000;
struct node
{
    // usless node:order=2*maxn
    int data, next, order, address;
};
vector<node> mylist(maxn);
bool isExist[maxn];
int main()
{
    memset(isExist, false, sizeof(isExist));
    int begin, n;
    cin >> begin >> n;
    for (auto &no : mylist)
    {
        no.order = 2 * maxn;
    }
    for (int i = 0; i < n; i++)
    {
        int add;
        cin >> add;
        mylist[add].address = add;
        scanf("%d%d", &mylist[add].data, &mylist[add].next);
    }
    int valid = 0;
    int removed = 0;
    int p = begin;
    while (p != -1)
    {
        int key = abs(mylist[p].data);
        if (!isExist[key])
        {
            isExist[key] = true;
            // valid node order:0 to valid-1
            mylist[p].order = valid++;
        }
        else
        {
            // removed node:maxn+remove
            mylist[p].order = maxn + removed++;
        }
        p = mylist[p].next;
    }
    sort(mylist.begin(), mylist.end(), [](node &a, node &b)
         { return a.order < b.order; });
    int count = valid + removed;
    for (int i = 0; i < count; i++)
    {
        if (i != valid - 1 && i != count - 1)
        {
            printf("%05d %d %05d\n", mylist[i].address, mylist[i].data, mylist[i + 1].address);
        }
        else
        {
            printf("%05d %d -1\n", mylist[i].address, mylist[i].data);
        }
    }

    return 0;
}