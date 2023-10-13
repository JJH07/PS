#include <iostream>
#include <algorithm>
#define MAX 100000
int n, m, list[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m;
    int l = 0, r = 10000 * n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
        l = std::max(l, list[i]);
    }
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        int cnt = 0, money = 0;
        for(int i = 0; i < n; i++)
        {
            if(money < list[i])
            {
                money = mid;
                cnt++;
            }
            money -= list[i];
        }
        if(cnt > m)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    std::cout << l << '\n';
    return 0;
}