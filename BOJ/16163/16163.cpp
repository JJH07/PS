#include <iostream>
#include <string>
#include <cstring>
#define MAX 4000002
typedef long long ll;
char str[MAX];
ll dp[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> str;
    int n = strlen(str);
    for(int i = n - 1; i >= 0; i--)
    {
        str[i * 2 + 1] = str[i];
        str[i * 2] =  '#';
    }
    str[n * 2] = '#';
    n = n * 2 + 1;

    int r = 0, p = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(i <= r)
        {
            dp[i] = std::min(dp[2 * p - i], 1LL * (r - i));
        }
        else
        {
            dp[i] = 0;
        }
        while(i - dp[i] - 1 >= 0 && i + dp[i] + 1 < n && str[i - dp[i] - 1] == str[i + dp[i] + 1])
        {
            dp[i]++;
        }
        if(r < i + dp[i])
        {
            r = i + dp[i];
            p = i;
        }
        ans += (dp[i] + 1) / 2;
    }
    std::cout << ans << '\n';
    return 0;
}