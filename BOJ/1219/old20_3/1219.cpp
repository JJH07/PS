#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MIN_V -1000000000
typedef long long ll;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, s, e, m;
    ll money[101], dist[100];
    std::vector<std::pair<int, ll>> adj[100];
    std::queue<int> check_list;
    bool FLAG = false;

    std::fill(dist, dist + 100, MIN_V);

    std::cin >> n >> s >> e >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        std::cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    for(int i = 0; i < n; i++)
    {
        std::cin >> money[i];
    }
    dist[s] = money[s];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(auto x : adj[j])
            {
                int next = x.first;
                int val = x.second;
                if(dist[j] != MIN_V && dist[next] < dist[j] + money[next] - val)
                {
                    dist[next] = dist[j] + money[next] - val;
                    if(i == n)
                    {
                        check_list.push(j);
                    }
                }
            }
        }
    }
    bool visited[100] = {0};
    while(!check_list.empty())
    {
        int front = check_list.front();
        check_list.pop();
        if(front == e)
        {
            FLAG = true;
            continue;
        }
        for(auto x : adj[front])
        {
            if(visited[x.first])
            {
                continue;
            }
            visited[x.first] = true;
            check_list.push(x.first);
        }
    }
    if(dist[e] == MIN_V)
    {
        std::cout << "gg\n";
    }
    else if(FLAG)
    {
        std::cout << "Gee\n";
    }
    else
    {
        std::cout << dist[e] << '\n';
    }
    return 0;
}