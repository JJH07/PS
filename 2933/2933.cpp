#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

int r, c, map[101][101];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int make_cluster_map()
{
    int visited[r + 1][c];
    int count = 0;
    std::queue<std::pair<int, int>> q;

    std::memset(visited, 0, sizeof(visited));

    for(int i = 1; i <= r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(visited[i][j])
            {
                continue;
            }
            if(map[i][j] > 0)
            {
                count++;
                visited[i][j] = 1;
                q.push({i, j});
                while(!q.empty())
                {
                    std::pair<int, int> front = q.front();
                    map[front.first][front.second] = count;
                    q.pop();
                    for(int di = 0; di < 4; di++)
                    {
                        int nx = front.first + dx[di];
                        int ny = front.second + dy[di];
                        if(nx < 1 || ny < 0 || nx > r || ny >= c || map[nx][ny] == 0 || visited[nx][ny])
                        {
                            continue;
                        }
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    return count;
}
void order(int count)
{
    int table[count + 1];
    std::fill(table, table + count + 1, 101);

    for(int c_i = 0; c_i < c; c_i++)
    {
        std::vector<int> pos(count + 1, 0);
        for(int r_i = r; r_i >= 1; r_i--)
        {
            if(map[r_i][c_i] > 0 && pos[map[r_i][c_i]] == 0)
            {
                pos[map[r_i][c_i]] = r_i;
            }
        }

        for(int idx = 1; idx <= count; idx++)
        {
            if(pos[idx] > 0)
            {
                int height = 0;
                for(int r_i = pos[idx] + 1; r_i <= r; r_i++)
                {
                    if(map[r_i][c_i] == 0)
                    {
                        height++;
                    }
                    else
                    {
                        break;
                    }
                }
                table[idx] = std::min(table[idx], height);
            }
        }
    }
    for(int c_i = 0; c_i < c; c_i++)
    {
        for(int r_i = r; r_i >= 1; r_i--)
        {
            if(map[r_i][c_i] > 0 && table[map[r_i][c_i]] > 0)
            {
                map[r_i + table[map[r_i][c_i]]][c_i] = map[r_i][c_i];
                map[r_i][c_i] = 0; 
            }
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> r >> c;
    
    for(int i = 1; i <= r; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        for(int j = 0; j < c; j++)
        {
            if(tmp[j] == 'x')
            {
                map[i][j] = 1;
            }
        }
    }
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int h;
        std::cin >> h;
        h = r - h + 1;
        if(i % 2)
        {
            for(int i = c - 1; i >= 0; i--)
            {
                if(map[h][i] > 0)
                {
                    map[h][i] = 0;
                    break;
                }
            }
        }
        else
        {
            for(int i = 0; i < c; i++)
            {
                if(map[h][i] > 0)
                {
                    map[h][i] = 0;
                    break;
                }
            }
        }
        int cluster_count = make_cluster_map();
        order(cluster_count);
    }
    for(int i = 1; i <= r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            std::cout << ((map[i][j] > 0) ? 'x' : '.');
        }
        std::cout << '\n';
    }
    return 0;
}