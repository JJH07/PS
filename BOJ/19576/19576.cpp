#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

int n, list[5000], memo[5000];
int solve(int now)
{
    int &ret = memo[now];
    if(ret != -1)
    {
        return ret;
    }
    ret = 1;
    for(int next = now + 1; next < n; next++)
    {
        if((list[next] % list[now]) == 0)
        {
            ret = std::max(ret, 1 + solve(next));
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(memo, -1, sizeof(memo));

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }
    std::sort(list, list + n);
    int MAX = 0;
    for(int i = 0; i < n; i++)
    {
        if(memo[i] == -1)
        {
            MAX = std::max(MAX, solve(i));
        }
    }
    std::cout << n - MAX << '\n';
    return 0;
}