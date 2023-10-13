#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define MAP_SZ 50
#define MAX 100
typedef std::pair<int, int> pii;
int r, c, c_sz, p_sz, map[MAP_SZ][MAP_SZ], match[MAX];
std::vector<pii> Car, link[MAX];
bool check[MAX];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
void input()
{
    std::string t;
    std::cin >> r >> c;
    for(int i = 0; i < r; i++)
    {
        std::cin >> t;
        for(int j = 0; j < c; j++)
        {
            if(t[j] == 'C')
            {
                Car.push_back({i, j});
            }
            else if(t[j] == 'P')
            {
                map[i][j] = ++p_sz;
            }
            else if(t[j] == 'X')
            {
                map[i][j] = -1;
            }
        }
    }
    c_sz = (int)Car.size();
}
void init_link()
{
    std::queue<std::pair<int, pii>> q;
    bool visited[MAP_SZ][MAP_SZ];

    for(int i = 0; i < c_sz; i++)
    {
        std::memset(visited, 0, sizeof(visited));
        pii s = Car[i];
        q.push({0, s});
        visited[s.first][s.second] = true;
        while(!q.empty())
        {
            auto [dist, pos] = q.front();
            q.pop();
            if(map[pos.first][pos.second] > 0)
            {
                link[i].push_back({map[pos.first][pos.second] - 1, dist});
            }
            for(int di = 0; di < 4; di++)
            {
                int nx = dx[di] + pos.first;
                int ny = dy[di] + pos.second;
                if(nx < 0 || ny < 0 || nx >= r || ny >= c || map[nx][ny] == -1 || visited[nx][ny])
                {
                    continue;
                }
                q.push({dist + 1, {nx, ny}});
                visited[nx][ny] = true;
            }
        }
    }
}
bool dfs(int car, int limit)
{
    if(check[car])
    {
        return false;
    }
    check[car] = true;
    for(auto [park, dist] : link[car])
    {
        if(dist > limit)
        {
            continue;
        }
        if(match[park] == -1 || dfs(match[park], limit))
        {
            match[park] = car;
            return true;
        }
    }
    return false;
}
int b_search()
{
    int s = 0, e = MAP_SZ * MAP_SZ, matched, ret = 1e9;
    while(s <= e)
    {
        matched = 0;
        int mid = (s + e) / 2;
        std::memset(match, -1, sizeof(match));
        for(int i = 0; i < c_sz; i++)
        {
            std::memset(check, 0, sizeof(check));
            matched += dfs(i, mid);
        }
        if(matched == c_sz)
        {
            ret = std::min(ret, mid);
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ret == 1e9 ? -1 : ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    input();
    init_link();
    std::cout << (c_sz == 0 ? 0 : b_search()) << '\n';
    return 0;
}