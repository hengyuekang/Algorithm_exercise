#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N;
double P, r;
const int maxn = 100000;
struct node
{
    double price = 0;
    int count = 0, parent = 0;
    vector<int> children;
};
bool isleaf[maxn] = {false};
node tree[maxn];
void bfs(int root)
{
    queue<int> q;
    q.emplace(root);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        for (auto c : tree[n].children)
        {
            q.emplace(c);
        }
        int par = tree[n].parent;
        if (par != -1)
        {
            tree[n].price = tree[par].price * (1.0 + 0.01 * r);
        }
    }
}
int main()
{
    cin >> N >> P >> r;
    for (int i = 0; i < N; i++)
    {
        int num = 0;
        cin >> num;
        if (num == 0)
        {
            int cnt = 0;
            cin >> cnt;
            isleaf[i] = true;
            tree[i].count = cnt;
        }
        else
        {
            int son = 0;
            for (int j = 0; j < num; j++)
            {
                cin >> son;
                tree[i].children.emplace_back(son);
                isleaf[i] = false;
                tree[son].parent = i;
            }
        }
    }
    tree[0].price = P;
    tree[0].parent = -1;
    bfs(0);
    double res = 0;
    for (int i = 0; i < N; i++)
    {
        if (isleaf[i])
        {
            res = res + (tree[i].price) * (tree[i].count);
        }
    }
    printf("%.1f", res);
    return 0;
}