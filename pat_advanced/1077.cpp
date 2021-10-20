#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N = 0;
int minLen = 256;
int main()
{
    int countCom = 0;
    cin >> N;
    cin.get();
    string line;
    vector<string> lines;
    for (int i = 0; i < N; i++)
    {
        getline(cin, line);
        lines.emplace_back(string(line.rbegin(), line.rend()));
        if (line.size() < minLen)
        {
            minLen = line.size();
        }
    }
    for (int i = 0; i < minLen; i++)
    {
        char c = lines[0][i];
        for (int j = 1; j < N; j++)
        {
            if (lines[j][i] != c)
            {
                goto end;
            }
        }
        countCom++;
    }
end:
    if (countCom == 0)
    {
        cout << "nai";
    }
    else
    {
        for (int i = countCom - 1; i >= 0; i--)
        {
            cout << lines[0][i];
        }
    }

    return 0;
}