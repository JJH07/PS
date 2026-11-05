#include <iostream>
#include <vector>
#include <algorithm>
const int MAX = 2e5;
int S[MAX], E[MAX], seg[MAX][2];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n;
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            std::cin >> S[i] >> E[i];
            seg[i][0] = S[i];
            seg[i][1] = E[i];
        }
        std::sort(S, S + n);
        std::sort(E, E + n);
        
        int ans = n - 1;
        for(int i = 0; i < n; i++)
        {
            int l = std::lower_bound(E, E + n, seg[i][0]) - E;
            int r = n - (std::upper_bound(S, S + n, seg[i][1]) - S);
            ans = std::min(ans, l + r);
        }
        std::cout << ans << '\n';
    }
    return 0;
}