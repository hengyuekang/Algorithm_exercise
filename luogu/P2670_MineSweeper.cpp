#include <iostream>
#include <cstring>
#include <cstdio>
int main()
{
    bool map[105][105];
    memset(map, 0, sizeof(map));
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    char grid;
    for (int row = 1; row < n + 1; row++)
    {
        for (int col = 1; col < m + 1; col++)
        {
            std::cin >> grid;
            if (grid == '*')
            {
                map[row][col] = true;
            }
        }
    }
    for (int row = 1; row < n + 1; row++)
    {
        for (int col = 1; col < m + 1; col++)
        {
            if (map[row][col])
            {
                std::cout << '*';
            }
            else
            {
                std::cout << map[row - 1][col - 1] + map[row - 1][col] + map[row - 1][col + 1] + map[row][col - 1] + map[row][col + 1] + map[row + 1][col - 1] + map[row + 1][col] + map[row + 1][col + 1];
            }
        }
        printf("\n");
    }
    return 0;
}