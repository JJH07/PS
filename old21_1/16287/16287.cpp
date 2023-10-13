#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 5000
int w, n, list[MAX];
bool dp[799995];
bool solve()
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(list[i] + list[j] > w)
            {
                break;
            }
            if(dp[w - list[i] - list[j]])
            {
                return true;
            }
        }
        for(int j = 0; j < i; j++)
        {
            dp[list[i] + list[j]] = true;
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> w >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }
    std::sort(list, list + n);
    std::cout << (solve() ? "YES\n" : "NO\n");
    return 0;
}
