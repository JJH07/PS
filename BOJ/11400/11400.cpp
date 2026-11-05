#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
typedef std::pair<int, int> pii;
int V, E;
std::vector<int> link[MAX];
std::vector<pii> ans;
int discovered[MAX], indexing;
int dfs(int now, int before)
{
    discovered[now] = ++indexing;
    int ret = indexing;
    for(auto next : link[now])
    {
        if(next == before)
        {
            continue;
        }
        if(!discovered[next])
        {
            int nret = dfs(next, now);
            if(discovered[now] < nret)
            {
                ans.push_back({std::min(now, next), std::max(now, next)});
            }
            ret = std::min(ret, nret);
        }
        else
        {
            ret = std::min(ret, discovered[next]);
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int a, b;
        std::cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }
    for(int i = 1; i <= V; i++)
    {
        if(!discovered[i])
        {
            dfs(i, -1);
        }
    }
    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << '\n';
    for(auto idx : ans)
    {
        std::cout << idx.first << ' ' << idx.second << '\n';
    }
    return 0;
}