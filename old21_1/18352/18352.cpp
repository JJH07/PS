#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 300001
typedef std::pair<int, int> pii;
int n, m, k, x;
bool visited[MAX];
std::vector<int> link[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> ans;
    std::queue<pii> q;
    std::cin >> n >> m >> k >> x;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        link[a].push_back(b);
    }
    visited[x] = true;
    q.push({x, 0});
    while(!q.empty())
    {
        auto [city, distance] = q.front();
        q.pop();
        if(distance > k)
        {
            break;
        }
        if(distance == k)
        {
            ans.push_back(city);
        }
        for(auto next : link[city])
        {
            if(!visited[next])
            {
                visited[next] = true;
                q.push({next, distance + 1});
            }
        }
    }
    std::sort(ans.begin(), ans.end());
    for(auto x : ans)
    {
        std::cout << x << '\n';
    }
    if(ans.size() == 0)
    {
        std::cout << "-1\n";
    }
    return 0;
}