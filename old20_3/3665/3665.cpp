#include <iostream>
#include <vector>
#include <cstring>

int rank[501], team[501], table[501];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n, m;
        std::cin >> n;
        for(int i = 1; i <= n; i++)
        {
            std::cin >> rank[i];
            team[rank[i]] = i;
            table[rank[i]] = n - i + 1;
        }
        std::cin >> m;
        for(int i = 0; i < m; i++)
        {
            int a, b;
            std::cin >> a >> b;
            if(team[a] > team[b])
            {
                std::swap(a, b);
            }
            table[a]--;
            table[b]++;
        }
        std::vector<int> ans;
        for(int i = n; i >= 0; i--)
        {
            for(int idx = 1; idx <= n; idx++)
            {
                if(table[idx] == i)
                {
                    ans.push_back(idx);
                    break;
                }
            }
        }
        if(ans.size() != n)
        {
            std::cout << "IMPOSSIBLE\n";
        }
        else
        {
            for(auto x : ans)
            {
                std::cout << x << ' ';
            }
            std::cout << '\n';
        }
    }
    return 0;
}