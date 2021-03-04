#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
void cal_result(std::vector<std::string> &data, int rule)
{
    std::vector<int> score(2, 0);
    for (auto &single_line : data)
    {
        for (auto &ball : single_line)
        {
            if (ball == 'W')
            {
                score[0]++;
            }
            if (ball == 'L')
            {
                score[1]++;
            }
            if (((score[0] >= rule) || (score[1] >= rule)) && abs(score[0] - score[1]) >= 2)
            {
                std::cout << score[0] << ":" << score[1] << std::endl;
                score[0] = 0;
                score[1] = 0;
            }
            if (ball == 'E')
            {
                std::cout << score[0] << ":" << score[1];
                if (rule == 11)
                {
                    printf("\n");
                }
                return;
            }
        }
    }
}
int main()
{
    // std::vector<std::string> score;
    std::vector<std::string> situation;
    std::string line;
    while ((std::cin >> line))
    {
        situation.push_back(line);
        if (line.find('E') != std::string::npos)
        {
            break;
        }
    }
    cal_result(situation, 11);
    printf("\n");
    cal_result(situation, 21);
    return 0;
}