#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int val;
    node *left, *right;
    node(int n) : val(n), left(nullptr), right(nullptr) {}
};

int N;
int cnt = 0;
vector<int> origin, pre, imag_pre;
// * &:only use root,but connect left and right
void insert(node *&root, int x)
{
    if (root == nullptr)
    {
        // find the place to insert
        root = new node(x);
        return;
    }
    else if (x < root->val)
    {
        insert(root->left, x);
    }
    else
    {
        insert(root->right, x);
    }
}
void preorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    pre.emplace_back(root->val);
    preorder(root->left);
    preorder(root->right);
}
void imagpreorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    imag_pre.emplace_back(root->val);
    imagpreorder(root->right);
    imagpreorder(root->left);
}
void postorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    if (cnt != 0)
    {
        cout << " ";
    }
    cout << root->val;
    cnt++;
}
void imgpostorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    imgpostorder(root->right);
    imgpostorder(root->left);
    if (cnt != 0)
    {
        cout << " ";
    }
    cout << root->val;
    cnt++;
}
int main()
{
    cin >> N;
    int num = 0;
    for (int i = 0; i < N; i++)
    {
        cin>>num;
        origin.emplace_back(num);
    }
    node *root = new node(origin[0]);
    for (int i = 1; i < N; i++)
    {
        insert(root, origin[i]);
    }
    preorder(root);
    imagpreorder(root);
    if (pre == origin)
    {
        cout << "YES\n";
        cnt = 0;
        postorder(root);
    }
    else if (origin == imag_pre)
    {
        cout << "YES\n";
        cnt = 0;
        imgpostorder(root);
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}