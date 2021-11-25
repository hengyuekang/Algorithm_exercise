#include <vector>
#include <iostream>
#include <queue>
//you can do better using index instead of pointer
using namespace std;
struct node
{
    int val = 0;
    node *left = nullptr, *right = nullptr, *parent = nullptr;
    node() = default;
};
int N;
void levelorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    int count = 0;
    queue<node *> q;
    q.emplace(root);
    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        if (count < N)
        {
            if (count != 0)
            {
                cout << " ";
            }
            cout << curr->val;
            count++;
        }

        if (curr->right != nullptr)
            q.push(curr->right);
        if (curr->left != nullptr)
            q.push(curr->left);
    }
}
int pcount = 0;
void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->right);
    // inorder(root->left);
    if (pcount < N)
    {
        if (pcount != 0)
        {
            cout << " ";
        }
        pcount++;
        cout << root->val;
    }
    // inorder(root->right);

    inorder(root->left);
}
// void postorder(node *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     postorder(root->left);
//     postorder(root->right);
//     swap(root->left, root->right);
// }
int main()
{
    cin >> N;
    vector<node *> nodes(N);
    for (auto &n : nodes)
    {
        n = new node();
    }
    for (int i = 0; i < N; i++)
    {
        string l, r;
        cin >> l >> r;
        nodes[i]->val = i;
        if (l != "-")
        {
            nodes[i]->left = nodes[atoi(l.c_str())];
            nodes[atoi(l.c_str())]->parent = nodes[i];
        }
        if (r != "-")
        {
            nodes[i]->right = nodes[atoi(r.c_str())];
            nodes[atoi(r.c_str())]->parent = nodes[i];
        }
    }
    node *root;
    for (auto n : nodes)
    {
        if (n->parent == nullptr)
        {
            root = n;
            break;
        }
    }
    levelorder(root);
    cout << "\n";
    inorder(root);
    return 0;
}