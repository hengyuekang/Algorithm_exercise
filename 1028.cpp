#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Student
{
    string id, name;
    int score;
};
vector<Student> stu;
int N, C;
bool cmp(Student &a, Student &b)
{
    switch (C)
    {
    case 1:
        return a.id < b.id;
        break;
    case 2:
    {
        if (a.name == b.name)
        {
            return a.id < b.id;
        }
        return a.name < b.name;
        break;
    }
    default:
    {
        if (a.score == b.score)
        {
            return a.id < b.id;
        }
        return a.score < b.score;
        break;
    }
    }
}
int main()
{
    cin >> N >> C;
    stu.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> stu[i].id >> stu[i].name >> stu[i].score;
    }
    sort(stu.begin(), stu.end(), cmp);
    for (auto s : stu)
    {
        cout << s.id << " " << s.name << " " << s.score << endl;
    }
    return 0;
}