#include <iostream>
#include <vector>
#include <algorithm>

struct Shark{
    int x;
    int y;
    int way;
    std::vector<int> priority[5];
};
int dx[5] = {0, -1, 1, 0, 0}, dy[5] = {0, 0, 0, -1, 1};
int movement(std::vector<Shark> &sharks, std::vector<int> &alive, std::vector<std::vector<std::pair<int, int>>> &smell, int n, int m, int k, int step)
{
    std::vector<int> map[n][n];
    for(int i = 1; i <= m; i++)
    {
        if(!alive[i])
        {
            continue;
        }
        int x = sharks[i].x;
        int y = sharks[i].y;
        int w = sharks[i].way;
        bool FLAG = false;
        for(auto p_idx = sharks[i].priority[w].begin(); p_idx != sharks[i].priority[w].end(); p_idx++)
        {
            int nx = dx[*p_idx] + x;
            int ny = dy[*p_idx] + y;
            if(nx >= 0 && ny >= 0 && nx < n && ny < n && smell[nx][ny].first == 0)
            {
                map[nx][ny].push_back(i);
                sharks[i].x = nx;
                sharks[i].y = ny;
                sharks[i].way = *p_idx;
                FLAG = true;
                break;
            }
        }
        if(FLAG)
        {
            continue;
        }
        for(auto p_idx = sharks[i].priority[w].begin(); p_idx != sharks[i].priority[w].end(); p_idx++)
        {
            int nx = dx[*p_idx] + x;
            int ny = dy[*p_idx] + y;
            if(nx >= 0 && ny >= 0 && nx < n && ny < n && smell[nx][ny].first == i)
            {
                map[nx][ny].push_back(i);
                sharks[i].x = nx;
                sharks[i].y = ny;
                sharks[i].way = *p_idx;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int _size = (int)map[i][j].size();
            if(_size > 0)
            {
                std::sort(map[i][j].begin(), map[i][j].end());
                for(int k = 1; k < _size; k++)
                {
                    alive[map[i][j][k]] = 0;
                }
                smell[i][j].first = map[i][j][0];
                smell[i][j].second = step;
            }
        }
    }

    int ret = 0;
    for(int i = 1; i <= m; i++)
    {
        ret += alive[i];
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, k, ans;
    std::cin >> n >> m >> k;
    std::vector<Shark> sharks(m + 1);
    std::vector<std::vector<std::pair<int, int>>> smell(n, std::vector<std::pair<int, int>>(n, {0, 0}));
    std::vector<int> alive(m + 1, 1);
    int step = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int idx;
            std::cin >> idx;
            if(idx > 0)
            {
                sharks[idx].x = i;
                sharks[idx].y = j;
                smell[i][j] = {idx, 0};
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        int w;
        std::cin >> w;
        sharks[i].way = w;
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                int w;
                std::cin >> w;
                sharks[i].priority[j].push_back(w);
            }
        }
    }

    while(step <= 1000)
    {
        if((ans = movement(sharks, alive, smell, n, m, k, step)) == 1)
        {
            break;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(smell[i][j].first == 0)
                {
                    continue;
                }
                if(step - smell[i][j].second >= k)
                {
                    smell[i][j].first = 0;
                    smell[i][j].second = 0;
                }
            }
        }
        step++;
    }
    if(ans == 1)
    {
        std::cout << step << '\n';
    }
    else
    {
        std::cout << "-1\n";
    }
    return 0;
}