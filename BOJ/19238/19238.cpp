#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
struct node
{
    int x;
    int y;
    int dist;
};
struct pq_node
{
    int dist;
    int x;
    int y;
    int idx;
    bool operator <(const pq_node &rhs) const
    {
        if(dist == rhs.dist)
        {
            if(x == rhs.x)
            {
                return y > rhs.y;
            }
            return x > rhs.x;
        }
        return dist > rhs.dist;
    };
};
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, fuel, now_idx = 0;
    std::cin >> n >> m >> fuel;
    std::vector<std::pair<int, int>> points(m * 2 + 1);
    std::vector<int> map[n + 1][n + 1];
    int visited[n + 1][n + 1];
    std::vector<std::vector<int>> blocked(n + 1, std::vector<int>(n + 1, 0)), distance(m * 2 + 1, std::vector<int>(m * 2 + 1, -1));
    std::vector<int> used(m * 2 + 1, 0);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> blocked[i][j];
        }
    }
    std::cin >> points[0].first >> points[0].second;
    for(int i = 1; i <= m * 2; i++)
    {
        std::cin >> points[i].first >> points[i].second;
    }
    for(int i = 0; i <= m * 2; i++)
    {
        map[points[i].first][points[i].second].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(map[i][j].size() > 0)
            {
                std::memset(visited, 0, sizeof(visited));

                std::vector<int> &from = map[i][j];
                std::queue<node> q;
                q.push({i, j, 0});
                visited[i][j] = 1;
                while(!q.empty())
                {
                    node front = q.front();
                    q.pop();
                    std::vector<int> to = map[front.x][front.y];
                    if(to.size() > 0)
                    {
                        for(auto f : from)
                        {
                            for(auto t : to)
                            {
                                distance[f][t] = front.dist;
                            }
                        }
                    }
                    for(int idx = 0; idx < 4; idx++)
                    {
                        int nx = dx[idx] + front.x;
                        int ny = dy[idx] + front.y;
                        if(nx <= 0 || ny <= 0 || nx > n || ny > n || blocked[nx][ny] || visited[nx][ny])
                        {
                            continue;
                        }
                        visited[nx][ny] = 1;
                        q.push({nx, ny, front.dist + 1});
                    }
                }
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        std::priority_queue<pq_node> pq;
        for(int idx = 1; idx <= m * 2; idx += 2)
        {
            if(used[idx])
            {
                continue;
            }
            if(distance[now_idx][idx] == -1)
            {
                continue;
            }
            pq.push({distance[now_idx][idx], points[idx].first, points[idx].second, idx});
        }
        if(pq.empty())
        {
            fuel = -1;
            break;
        }
        int next_idx = pq.top().idx;
        if(distance[next_idx][next_idx + 1] == -1)
        {
            fuel = -1;
            break;
        }
        if(distance[now_idx][next_idx] + distance[next_idx][next_idx + 1] > fuel)
        {
            fuel = -1;
            break;
        }
        fuel += (distance[next_idx][next_idx + 1] - distance[now_idx][next_idx]);
        used[next_idx] = 1;
        used[next_idx + 1] = 1;
        now_idx = next_idx + 1;
    }
    std::cout << fuel << '\n';
    return 0;
}