#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100000;
struct node
{
    int order;
    int add,data,next;
};
vector<node> nodes(maxn);
int main()
{
    for(auto &n:nodes)
    {
        // not useful
        n.order=maxn;
    }
    int begin,n,k,address;
    scanf("%d%d%d",&begin,&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&address);
        nodes[address].add=address;
        scanf("%d%d",&nodes[address].data,&nodes[address].next);
    }
    int p=begin;
    int count=0;
    while(p!=-1)
    {
        nodes[p].order=count;
        p=nodes[p].next;
        count++;
    }
    // clear the uesless(not linked by begining address) node
    n=count;

    sort(nodes.begin(),nodes.end(),[](node &a,node &b){ return a.order<b.order;});
    // iterater all the whole blocks
    for(int i=0;i<n/k;i++)
    {
        // the next address for the last node in the block is not determined
        // its may be the address of node which is the first or last block in next block
        for(int j=(i+1)*k-1;j>i*k;j--)
        {
            printf("%05d %d %05d\n",nodes[j].add,nodes[j].data,nodes[j-1].add);
        }
        printf("%05d %d ",nodes[i*k].add,nodes[i*k].data);
        if(i<(n/k-1))
        {
            printf("%05d\n",nodes[(i+2)*k-1].add);
        }
        else
        {
            // last block,but not always include the last node
            if((n%k)==0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%05d\n",nodes[(i+1)*k].add);
                for(int m=(i+1)*k;m<n-1;m++)
                {
                    printf("%05d %d %05d\n",nodes[m].add,nodes[m].data,nodes[m+1].add);
                }
                printf("%05d %d -1\n",nodes[n-1].add,nodes[n-1].data);
            }
        }
    }
    return 0;
}