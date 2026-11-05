#include <iostream>
#include <vector>
#include <queue>
#define hMAX 1001
#define sMAX 100001
typedef std::pair<int, int> pii;
int n, k, m;
std::vector<int> hyper[hMAX], station[sMAX];
int svisited[sMAX], hvisited[hMAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k >> m;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < k; j++)
        {
            int s;
            std::cin >> s;
            hyper[i].push_back(s);
            station[s].push_back(i);
        }
    }
    int ans = -1;
    std::queue<pii> q;
    q.push({1, 1});
    svisited[1] = true;
    while(!q.empty())
    {
        auto [s, c] = q.front();
        q.pop();
        if(s == n)
        {
            ans = c;
            break;
        }
        for(int h : station[s])
        {
            if(hvisited[h])
            {
                continue;
            }
            hvisited[h] = true;
            for(int ns : hyper[h])
            {
                if(svisited[ns])
                {
                    continue;
                }
                svisited[ns] = true;
                q.push({ns, c + 1});
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}