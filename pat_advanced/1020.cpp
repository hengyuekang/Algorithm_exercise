#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node
{
    int val;
    node *left,*right;
};
int length;
vector<int> post,in;
node *create(int postl,int postr,int inl,int inr)
{
    if(postl>postr)
    {
        return NULL;
    }
    node *res=new node;
    res->val=post[postr];
    int k=inl;
    for(;k<=inr;k++)
    {
        if(in[k]==post[postr])
        {
            break;
        }
    }
    res->left=create(postl,postl+k-inl-1,inl,k-1);
    res->right=create(postl+k-inl,postr-1,k+1,inr);
    return res;
}
void BFS(node *tree)
{
    int num=0;
    queue<node*> Q;
    Q.push(tree);
    // cout<<tree->val;
    while(!Q.empty())
    {
        node *n=Q.front();
        Q.pop();
        num++;
        if((num>1))
        {
            cout<<" ";
        }
        cout<<n->val;
        if((n->left!=NULL))
        {
            Q.push(n->left);
        }
        if((n->right!=NULL))
        {
            Q.push(n->right);
        }
    }
}
int main()
{
    cin>>length;
    for(int i=0;i<length;i++)
    {
        int num;
        cin>>num;
        post.emplace_back(num);
    }
    for(int i=0;i<length;i++)
    {
        int num;
        cin>>num;
        in.emplace_back(num);
    }
    node *tree=create(0,length-1,0,length-1);
    BFS(tree);
    return 0;
}