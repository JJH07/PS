#include <iostream>
#define MAX 1000001
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n, m, ans = 0;
        std::cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            int t;
            std::cin >> t;
            ans += t;
        }
        std::cout << (ans == m ? "YES\n" : "NO\n");
    }
    return 0;
}