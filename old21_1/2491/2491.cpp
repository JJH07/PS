#include <iostream>

int list[100001], ans = 1;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, UP = 1, DOWN = 1;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> list[i];
    }
    for(int i = 2; i <= n; i++)
    {
        if(list[i] >= list[i - 1])
        {
            UP++;
        }
        else
        {
            UP = 1;
        }
        if(list[i] <= list[i - 1])
        {
            DOWN++;
        }
        else
        {
            DOWN = 1;
        }
        ans = std::max(ans, std::max(UP, DOWN));
    }
    std::cout << ans << '\n';
    return 0;
}