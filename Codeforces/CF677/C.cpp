#include <iostream>
#include <vector>
#include <queue>

int list[300001];
int find_ans(int sz, int mx)
{
    int dx[2] = {-1, 1};
    for(int i = 1; i <= sz; i++)
    {
        if(list[i] == mx)
        {
            for(int idx = 0; idx < 2; idx++)
            {
                int ni = dx[idx] + i;
                if(ni < 1 || ni > sz)
                {
                    continue;
                }
                if(list[i] > list[ni])
                {
                    return i;
                }
            }
        }
    }
    return -1;
}
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
        int MAX = -1;
        for(int i = 1; i <= n; i++)
        {
            std::cin >> list[i];
            if(list[i] > MAX)
            {
                MAX = list[i];
            }
        }
        std::cout << find_ans(n, MAX) << '\n';
    }
    return 0;
}