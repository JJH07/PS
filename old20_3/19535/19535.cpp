#include <iostream>
#include <vector>
#include <cstring>

typedef long long ll;
ll d, g;
int n;
std::vector<int> node[300001];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
    {
        ll sz = (ll)node[i].size();

        if(sz >= 2)
        {
            for(auto next : node[i])
            {
                ll next_sz = (ll)node[next].size();
                if(next_sz > 1)
                {
                    d += (next_sz - 1) * (sz - 1);
                }
            }
        }
        if(sz >= 3)
        {
            g += sz * (sz - 1) * (sz - 2) / 6;
        }
    }
    d /= 2;
    g *= 3;
    if(d > g)
    {
        std::cout << "D\n";
    }
    else if(d == g)
    {
        std::cout << "DUDUDUNGA\n";
    }
    else
    {
        std::cout << "G\n";
    }
    return 0;
}