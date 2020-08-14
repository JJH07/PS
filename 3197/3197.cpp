#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>

#define MAX_PARENT 1500 * 1500 / 2

struct node{
    int x;
    int y;
    int idx;
};
int r, c, water_count, group_table[1500][1500], parent[MAX_PARENT + 1];
int L1, L2;
std::string map[1500];
std::vector<std::pair<int, int>> L;
std::queue<node> next;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int Find(int idx)
{
    if(parent[idx] < 0)
    {
        return idx;
    }
    return parent[idx] = Find(parent[idx]);
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b)
    {
        return ;
    }
    if(parent[a] > parent[b])
    {
        parent[b] += parent[a];
        parent[a] = b;
    }
    else
    {
        parent[a] += parent[b];
        parent[b] = a;
    }
    
}
void init()
{
    std::queue<node> q;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(group_table[i][j] == 0 && map[i][j] != 'X')
            {
                water_count++;
                q.push({i, j, water_count});
                group_table[i][j] = water_count;
                while(!q.empty())
                {
                    node front = q.front();
                    q.pop();
                    for(int di = 0; di < 4; di++)
                    {
                        int nx = dx[di] + front.x;
                        int ny = dy[di] + front.y;
                        if(nx < 0 || ny < 0 || nx >= r || ny >= c || group_table[nx][ny] > 0)
                        {
                            continue;
                        }
                        group_table[nx][ny] = front.idx;
                        if(map[nx][ny] == 'X')
                        {
                            next.push({nx, ny, water_count});
                        }
                        else
                        {
                            q.push({nx, ny, water_count});
                        }
                    }
                }
            }
        }
    }
    L1 = group_table[L[0].first][L[0].second];
    L2 = group_table[L[1].first][L[1].second];
}
bool check(std::queue<node> now)
{
    while(!now.empty())
    {
        node front = now.front();
        now.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + front.x;
            int ny = dy[i] + front.y;
            if(nx < 0 || ny < 0 || nx >= r || ny >= c || group_table[nx][ny] == 0)
            {
                continue;
            }
            if(group_table[nx][ny] == front.idx)
            {
                continue;
            }
            int p1 = Find(front.idx);
            int p2 = Find(group_table[nx][ny]);
            if(p1 != p2)
            {
                Union(p1, p2);
            }
        }
    }
    return Find(L1) == Find(L2);
}
void days_gone(std::queue<node> &now)
{
    std::queue<node> temp;
    while(!now.empty())
    {
        node front = now.front();
        now.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + front.x;
            int ny = dy[i] + front.y;
            if(nx < 0 || ny < 0 || nx >= r || ny >= c || group_table[nx][ny] > 0)
            {
                continue;
            }
            group_table[nx][ny] = front.idx;
            temp.push({nx, ny, front.idx});
        }
    }
    next = temp;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(parent, parent + MAX_PARENT + 1, -1);

    std::cin >> r >> c;
    for(int i = 0; i < r; i++)
    {
        std::cin >> map[i];
        for(int j = 0; j < c; j++)
        {
            if(map[i][j] == 'L')
            {
                L.push_back(std::make_pair(i, j));
            }
        }
    }
    init();
    int day = 1;
    while(1)
    {
        if(check(next))
        {
            break;
        }
        days_gone(next);
        day++;
    }
    std::cout << day << '\n';
    return 0;
}