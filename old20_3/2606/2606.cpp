#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, ans = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int>> link(n + 1);
    std::vector<int> visited(n + 1, 0);
    std::queue<int> q;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }
    q.push(1);
    visited[1] = 1;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(int next : link[front])
        {
            if(!visited[next])
            {
                ans++;
                q.push(next);
                visited[next] = 1;
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}