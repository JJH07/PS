#include <iostream>
#include <algorithm>

int playerCount, white[1001], black[1001], dp[16][16][1001];
int maxScore(int w, int b, int idx)
{
    if(idx == playerCount)
    {
        return 0;
    }
    if(w + b == 30)
    {
        return 0;
    }
    int &result = dp[w][b][idx];
    if(result != -1)
    {
        return result;
    }
    result = 0;
    if(w < 15)
    {
        result = white[idx] + maxScore(w + 1, b, idx + 1);
    }
    if(b < 15)
    {
        result = std::max(result, black[idx] + maxScore(w, b + 1, idx + 1));
    }
    result = std::max(result, maxScore(w, b, idx + 1));
    return result;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(auto &whiteCount : dp)
    {
        for(auto &row : whiteCount)
        {
            std::fill(row, row + 1001, -1);
        }
    }


    while(!(std::cin >> white[playerCount] >> black[playerCount]).eof())
    {
        playerCount++;
    }
    std::cout << maxScore(0, 0, 0) << '\n';
    return 0;
}
