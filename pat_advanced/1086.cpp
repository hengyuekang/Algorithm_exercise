#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node *left, *right;
};
stack<int> input;
int N;
int pre[50], in[50],post[50];
node *create(int preL,int preR,int inL,int inR)
{
    if(preL>preR) return nullptr;
    node *root=new node;
    root->val=pre[preL];
    int k=inL;
    for(;k<=inR;k++)
    {
        if(in[k]==pre[preL])
        {
            break;
        }
    }
    root->left=create(preL+1,preL+k-inL,inL,k-1);
    root->right=create(preL+k-inL+1,preR,k+1,inR);
    return root;
}
int cnt=0;
void preorder(node *root)
{
    if(root==nullptr)
    {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->val;
    if(cnt<N-1)
    {
        cout<<" ";
        cnt++;
    }
}
int main()
{
    cin >> N;
    string op;
    int num,shc=0,opc=0;
    for (int i = 0; i < 2*N; i++)
    {
        cin>>op;
        if(op=="Push")
        {
            cin>>num;
            input.push(num);
            pre[shc++] =num;
        }
        else
        {
            in[opc++]=input.top();
            input.pop();
        }
    }
    node *root=create(0,N-1,0,N-1);
    preorder(root);
    return 0;
}