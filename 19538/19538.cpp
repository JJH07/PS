#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n;
    std::vector<std::vector<int>> link(n + 1);
    std::vector<int> infect_time(n + 1, -1), neighbor(n + 1);
    std::queue<int> keep;
    std::queue<std::pair<int, int>> q;
    for(int i = 1; i <= n; i++)
    {
        int con;
        while(1)
        {
            std::cin >> con;
            if(con == 0)
            {
                break;
            }
            link[i].push_back(con);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int sz = (int)link[i].size();
        neighbor[i] = sz % 2 ? sz / 2 + 1 : sz / 2;
    }
    std::cin >> m;
    for(int i = 0; i < m; i++)
    {
        int host;
        std::cin >> host;
        q.push(std::make_pair(host, 0));
        infect_time[host] = 0;
        keep.push(host);
    }
    int tick = -1;
    while(!q.empty())
    {
        std::pair<int, int> front = q.front();
        q.pop();
        int idx = front.first;
        int time = front.second;
        if(tick < time)
        {
            tick = time;
            while(!keep.empty())
            {
                int now = keep.front();
                keep.pop();
                for(int next : link[now])
                {
                    neighbor[next]--;
                }
            }
        }
        for(int next : link[idx])
        {
            if(infect_time[next] != -1)
            {
                continue;
            }
            if(neighbor[next] <= 0)
            {
                q.push(std::make_pair(next, time + 1));
                infect_time[next] = time + 1;
                keep.push(next);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        std::cout << infect_time[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}