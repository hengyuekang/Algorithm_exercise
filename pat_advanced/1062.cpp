#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
struct info
{
    string id;
    int vg = 0, tg = 0, sum = 0;
    // just sort a whole array once,flag determine the max printing order
    int flag;
};
// order only using this one
bool cmp(info &a, info &b)
{
    // return a boolean expression to subtract situation
    if (a.flag != b.flag)
        return a.flag < b.flag;
    else if (a.sum != b.sum)
        return a.sum > b.sum;
    else if (a.vg != b.vg)
        return a.vg > b.vg;
    else
        return a.id < b.id;
}
int main()
{
    vector<info> students;
    int all = 0, low = 0, high = 0;
    scanf("%d%d%d", &all, &low, &high);
    for (int i = 0; i < all; i++)
    {
        info people;
        cin >> people.id;
        scanf("%d%d", &people.vg, &people.tg);
        people.sum = people.vg + people.tg;
        if (people.tg < low || people.vg < low)
        {
            continue;
        }
        else if (people.tg >= high && people.vg >= high)
        {
            people.flag = 1;
            students.emplace_back(people);
        }
        else if (people.vg >= high && people.tg < high)
        {
            people.flag = 2;
            students.emplace_back(people);
        }
        else if (people.vg >= people.tg)
        {
            people.flag = 3;
            students.emplace_back(people);
        }
        else
        {
            people.flag = 4;
            students.emplace_back(people);
        }
    }
    printf("%d\n", students.size());
    sort(students.begin(), students.end(), cmp);
    for (auto v : students)
    {
        cout << v.id;
        printf(" %d %d\n", v.vg, v.tg);
    }

    return 0;
}