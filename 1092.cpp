#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;
map<char, int> beads;
string shop, own;
int main()
{
    bool res, rres = true;
    cin >> shop >> own;
    for (auto c : shop)
    {
        if (beads.count(c) == 0)
        {
            beads[c] = 1;
        }
        else
        {
            beads[c]++;
        }
    }
    int tmp = 0;
    for (auto c : own)
    {
        if (beads.count(c) == 0)
        {
            tmp++;
            res = rres = false;
        }
        else
        {
            if (beads[c] == 0)
            {
                tmp++;
                res = rres = false;
            }
            else
            {
                beads[c]--;
                res = true;
            }
        }
    }
    if (rres)
    {
        int r = abs((int)(shop.size() - own.size()));
        cout << "Yes " << r;
    }
    else
    {
        cout << "No " << tmp;
    }

    return 0;
}