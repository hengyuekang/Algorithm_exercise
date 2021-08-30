// #include <iostream>
// #include <vector>
// #include <set>
// using namespace std;
// int M, N, K;
// int main()
// {
//     cin >> M >> N >> K;
//     vector<int> stacks;
//     for (int i = 0; i < N; i++)
//     {
//         stacks.emplace_back(i + 1);
//     }
//     vector<vector<int>> seq(K);
//     for (int i = 0; i < K; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             int num = 0;
//             cin >> num;
//             seq[i].emplace_back(num);
//         }
//     }
//     vector<vector<int>> clip(K);
//     for (int i = 0; i < K; i++)
//     {
//         clip[i].emplace_back(seq[i][0]);
//         for (int next = 1; next < N; next++)
//         {
//             if (seq[i][next] > seq[i][next - 1])
//             {
//                 clip[i].emplace_back(seq[i][next]);
//             }
//         }
//         set<int> temp(clip[i].begin(), clip[i].end());
//         if ((clip[i].size() <2)||(temp.size()!=clip[i].size()))
//         {
//             cout << "NO\n";
//         }
//         else
//         {
//             for (int j = 0; j < clip[i].size() - 1; j++)
//             {
//                 if (((clip[i][j + 1] - clip[i][j]) > 0) && ((clip[i][j + 1] - clip[i][j]) <= M))
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     cout << "NO\n";
//                     goto next_seq;
//                 }
//             }
//             cout << "YES\n";
//         }
//     next_seq:;
//     }
//     return 0;
// }
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; i++) {
        bool flag = false;
        stack<int> s;
        vector<int> v(n + 1);
        for(int j = 1; j <= n; j++)
            scanf("%d", &v[j]);
        int current = 1;
        for(int j = 1; j <= n; j++) {
            s.push(j);
            if(s.size() > m) break;
            while(!s.empty() && s.top() == v[current]) {
                s.pop();
                current++;
            }
        }
        if(current == n + 1) flag = true;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
// every elment of the seqence represents the top of stack
// my method did not take the actual situation of stack into consideration