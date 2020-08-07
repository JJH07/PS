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
    std::vector<int> infect_time(n + 1, -1), neighbor_infected(n + 1, 0);
    std::queue<int> preprocess;
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
    std::cin >> m;
    for(int i = 0; i < m; i++)
    {
        int host;
        std::cin >> host;
        q.push(std::make_pair(host, 0));
        infect_time[host] = 0;
        for(int next : link[host])
        {
            neighbor_infected[next]++;
        }
    }
    int tick = 0;
    while(!q.empty())
    {
        std::pair<int, int> front = q.front();
        int idx = front.first;
        int time = front.second;
        std::cout << idx << ' ' << time << '\n';
        q.pop();
        if(tick != time)
        {
            while(!preprocess.empty())
            {
                int idx = preprocess.front();
                preprocess.pop();
                for(int next : link[idx])
                {
                    neighbor_infected[next]++;
                }
            }
            tick = time;
        }
        for(int next : link[idx])
        {
            if(infect_time[next] != -1)
            {
                continue;
            }
            if(neighbor_infected[next] * 2 >= (int)link[next].size())
            {
                infect_time[next] = time + 1;
                q.push(std::make_pair(next, time + 1));
                preprocess.push(next);
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