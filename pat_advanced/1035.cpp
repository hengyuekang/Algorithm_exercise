// #include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<char, char> modifyChar = {{'1', '@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'}};
int N;
vector<pair<string, string>> accounts;
int main()
{
    int iModify = 0;
    int modifyC = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string account, password;
        cin >> account >> password;
        modifyC = 0;
        for (auto &c : password)
        {
            if (c == '1' || c == '0' || c == 'l' || c == 'O')
            {
                c = modifyChar[c];
                modifyC++;
            }
        }
        if (modifyC != 0)
        {
            iModify++;
            accounts.emplace_back(make_pair(account, password));
        }
    }
    if (iModify != 0)
    {
        cout << iModify << endl;
        for (auto a : accounts)
        {
            cout << a.first << " " << a.second << endl;
        }
    }
    else
    {
        if (N == 1)
        {
            cout << "There is 1 account and no account is modified";
        }
        else
        {
            cout << "There are " << N << " accounts and no account is modified";
        }
    }
    return 0;
}
