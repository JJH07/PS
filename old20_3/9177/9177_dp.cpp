#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

std::string word[3];
int len[3], dp[201][201];
int solve(int i, int j)
{
    if(i + j == len[2])
    {
        return 1;
    }
    int &ret = dp[i][j];
    if(ret != -1)
    {
        return ret; 
    }
    ret = 0;
    if(i < len[0] && word[2][i + j] == word[0][i])
    {
        ret = solve(i + 1, j);
    }
    if(ret)
    {
        return ret;
    }
    if(j < len[1] && word[2][i + j] == word[1][j])
    {
        ret = solve(i, j + 1);
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::memset(dp, -1, sizeof(dp));
        for(int j = 0; j < 3; j++)
        {
            std::cin >> word[j];
            len[j] = word[j].length();
        }
        std::cout << "Data set " << i << ": " << (solve(0, 0) ? "yes" : "no") << '\n';
    }
    return 0;
}