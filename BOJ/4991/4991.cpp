//
//  main.cpp
//  4991
//
//  Created by 진준호 on 2020/02/12.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <cstring>
#include <climits>
struct q_idx{
    int x;
    int y;
    int d;
};

int n, m, distance[11][11], dp[11][1 << 12];
std::string map[21];
std::deque<std::pair<int, int>> dirty_pos;
int solve(int now, int state)
{
    int &ret = dp[now][state];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    int pos_size = (int)dirty_pos.size();
    int tmp = INT_MAX;
    for(int i = 1; i < pos_size; i++)
    {
        if(!(state & (1 << i)))
        {
            tmp = std::min(tmp, distance[now][i] + solve(i, state + (1 << i)));
        }
    }
    return (tmp == INT_MAX) ? ret : ret += tmp;
}
bool make_distance()
{
    int visited[n][m], deque_size = (int)dirty_pos.size();
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    std::queue<q_idx> q;
    q_idx front, dest;
    
    for(int i = 0; i < deque_size; i++)
    {
        for(int j = i + 1; j < deque_size; j++)
        {
            bool found = false;
            std::memset(visited, 0, sizeof(visited));
            
            dest.x = dirty_pos[j].first;
            dest.y = dirty_pos[j].second;
            
            q.push({dirty_pos[i].first, dirty_pos[i].second, 0});
            visited[dirty_pos[i].first][dirty_pos[i].second] = 1;
            while(!q.empty())
            {
                front = q.front();
                q.pop();
                if(map[front.x][front.y] == 'x')
                {
                    continue;
                }
                if(front.x == dest.x && front.y == dest.y)
                {
                    found = true;
                    break;
                }
                for(int i = 0; i < 4; i++)
                {
                    int nx = dx[i] + front.x;
                    int ny = dy[i] + front.y;
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] == 1)
                    {
                        continue;
                    }
                    visited[nx][ny] = 1;
                    q.push({nx, ny, front.d + 1});
                }
            }
            if(found)
            {
                distance[i][j] = front.d;
                distance[j][i] = front.d;
                while(!q.empty())
                {
                    q.pop();
                }
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    while(1)
    {
        std::cin >> m >> n;
        if(n == 0 && m == 0)
        {
            break;
        }
        
        int sx, sy;
        
        for(int i = 0; i < n; i++)
        {
            std::cin >> map[i];
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(map[i][j] == 'o')
                {
                    sx = i;
                    sy = j;
                }
                if(map[i][j] == '*')
                {
                    dirty_pos.push_back({i, j});
                }
            }
        }
        dirty_pos.push_front({sx, sy});
        
        if(!make_distance())
        {
            std::cout << "-1\n";
        }
        else
        {
            std::memset(dp, -1, sizeof(dp));
            std::cout << solve(0, 1) << '\n';
        }
        dirty_pos.clear();
    }
    
    return 0;
}
