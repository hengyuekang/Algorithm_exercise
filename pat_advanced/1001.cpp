#include <iostream>
#include <stack>
int main()
{
    int a = 0, b = 0;
    std::stack<std::pair<int, std::string>> res;
    std::cin >> a >> b;
    int num = a + b;
    std::pair<int, std::string> digit;
    int cnt = -1;
    if (num < 0)
    {
        std::cout << "-";
        num = -num;
    }
    if (num == 0)
    {
        std::cout << "0";
        return 0;
    }

    while (num > 0)
    {
        digit.first = num % 10;
        num /= 10;
        cnt++;
        if (cnt == 3 && res.size() != 0)
        {
            digit.second = ",";
            cnt = 0;
        }
        res.push(digit);
        digit.second = " ";
    }
    while (!res.empty())
    {
        digit = res.top();
        std::cout << digit.first;
        if (digit.second == ",")
        {
            std::cout << digit.second;
        }

        res.pop();
    }

    return 0;
}