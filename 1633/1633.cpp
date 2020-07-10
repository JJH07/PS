#include <iostream>
#include <vector>
#include <algorithm>

int count, white[1001], black[1001], dp[16][16][1001];
int solve(int w, int b, int idx)
{
    if(idx == count)
    {
        return 0;
    }
    if(w + b == 30)
    {
        return 0;
    }
    int &ret = dp[w][b][idx];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    if(w < 15)
    {
        ret = white[idx] + solve(w + 1, b, idx + 1);
    }
    if(b < 15)
    {
        ret = std::max(ret, black[idx] + solve(w, b + 1, idx + 1));
    }
    ret = std::max(ret, solve(w, b, idx + 1));
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    std::fill(dp[0][0], dp[0][0] + 16 * 16 * 1001, -1);


    while(!(std::cin >> white[count] >> black[count]).eof())
    {
        count++;
    }
    std::cout << solve(0, 0, 0) << '\n';
    return 0;
}