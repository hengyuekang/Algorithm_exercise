#include <iostream>
#include <vector>
// to avoid recursion,and just use relationships between index,store middle result in array
// int cal_num(int N, int K)
// {
//     if (N == 1||N==0)
//     {
//         return 1;
//     }
//     int time = 0;
//     if(N<=K)
//     {
//         return 2*cal_num(N-1,K);
//     }
//     // N-K-1>=0
//     time=2*cal_num(N-1,K)-cal_num(N-K-1,K);
//     return time;
// }
int main()
{
    const int mod = 100003;

    int num_steps = 0;
    int max_step = 0;
    std::vector<int> results(1000000, 0);
    results[0] = results[1] = 1;
    std::cin >> num_steps >> max_step;
    for (int i = 2; i < num_steps + 1; i++)
    {
        // calculate every result before num_steps,regard n as num_steps
        if (i <= max_step)
        {
            results[i] = results[i - 1] * 2;
        }
        else
        {
            results[i] = 2 * results[i - 1] - results[i - max_step - 1];
        }
        // results can be very large,stroe it using mod
        results[i] %= mod;
    }
    // +mod in case of borrowing when subtracting
    std::cout << (results[num_steps] + mod) % mod << std::endl;
    return 0;
}