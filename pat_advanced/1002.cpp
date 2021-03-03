#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>
int main()
{
    std::list<std::pair<int, double>> A;
    std::list<std::pair<int, double>> B;
    int Ka = 0, Kb = 0;
    std::cin >> Ka;
    std::pair<int, double> numA = {Ka, 0.0};
    A.push_back(numA);
    int exp = 0;
    double coef = 0.0;
    std::pair<int, double> item = {exp, coef};
    if (Ka != 0)
    {
        while (std::cin.get() != '\n')
        {
            std::cin >> item.first >> item.second;
            A.push_back(item);
        }
    }

    std::cin >> Kb;
    std::pair<int, double> numB = {Kb, 0.0};
    B.push_back(numB);
    if (Kb != 0)
    {
        while (std::cin.get() != '\n')
        {
            std::cin >> item.first >> item.second;
            B.push_back(item);
        }
    }

    auto itA = ++A.begin();
    auto itB = ++B.begin();
    // A add B
    while (itA != A.end())
    {
        while (itB != B.end())
        {
            if (itA->first == itB->first)
            {
                itB->second += itA->second;
                if (itB->second == 0.0)
                {
                    itB = B.erase(itB);
                    itB++;
                }
                break;
            }
            if (itB == --B.end())
            {
                B.push_back(*itA);
                break;
            }
            itB++;
        }
        itB = ++B.begin();
        itA++;
    }
    auto itB1 = ++B.begin();
    auto itB2 = ++(++B.begin());
    // merge items have the same exp
    while (itB1 != B.end())
    {
        while (itB2 != B.end())
        {
            if (itB1->first == itB2->first)
            {
                itB1->second += itB2->second;
                itB2 = B.erase(itB2);
                continue;
            }
            itB2++;
        }
        itB1++;
        auto temp = itB1;
        itB2 = ++temp;
    }
    Kb = B.size() - 1;
    std::cout << Kb;
    auto it = B.begin();
    it = B.erase(it);
    B.sort([](auto &A, auto &B) { return A.first > B.first; });
    it = B.begin();
    if (Kb != 0)
    {
        while (it != B.end())
        {
            std::cout << " " << it->first;
            std::cout << " " << setiosflags(std::ios::fixed) << std::setprecision(1) << it->second;
            it++;
        }
    }

    return 0;
}

