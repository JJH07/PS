#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

bool visited[100001];
int trace[100001];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(trace, -1, sizeof(trace));

    int n, k;
    std::queue<std::pair<int, int>> q;
    std::cin >> n >> k;
    q.push({n, 0});
    visited[n] = 1;
    while(!q.empty())
    {
        auto [now, time] = q.front();
        q.pop();
        if(now == k)
        {
            std::cout << time << '\n';
            break;
        }
        int next[3] = {now - 1, now + 1, now + now};
        for(int i = 0; i < 3; i++)
        {
            if(next[i] >= 0 && next[i] <= 100000 && !visited[next[i]])
            {
                q.push({next[i], time + 1});
                visited[next[i]] = 1;
                trace[next[i]] = now;
            }
        }
    }
    std::vector<int> ans;
    int tracing = k;
    while(tracing >= 0)
    {
        ans.push_back(tracing);
        tracing = trace[tracing];
    }
    for(auto x = ans.rbegin(); x != ans.rend(); x++)
    {
        std::cout << *x << ' ';
    }
    return 0;
}