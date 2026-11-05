#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100001
int n, k, time_table[MAX], dp[MAX];
int dx[3] = {1, -1, 0};
int bfs()
{
    std::queue<std::pair<int, int>> q;
    std::fill(time_table, time_table + MAX, MAX);
    int ret = 0;
    q.push({n, 0});
    time_table[n] = 0;
    dp[n] = 1;
    while(!q.empty())
    {
        auto [POS, T] = q.front();
        q.pop();
        if(POS == k)
        {
            ret = T;
            break;
        }
        for(int i = 0; i < 3; i++)
        {
            int nPOS = POS + (i == 2 ? POS : dx[i]);
            if(nPOS < 0 || nPOS >= MAX || (time_table[nPOS] < T + 1))
            {
                continue;
            }
            if(time_table[nPOS] == T + 1)
            {
                dp[nPOS] += dp[POS];
            }
            else
            {
                dp[nPOS] = dp[POS];
                time_table[nPOS] = T + 1;
                q.push({nPOS, T + 1});
            }
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> k;
    std::cout << bfs() << '\n' << dp[k] << '\n';
    return 0;
}