//
//  main.cpp
//  17822
//
//  Created by 진준호 on 2020/04/13.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, t, x, d, k, circle[51][51], visited[51][51];
    
    std::cin >> n >> m >> t;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            std::cin >> circle[i][j];
        }
    }
    for(int turn = 0; turn < t; turn++)
    {
        std::cin >> x >> d >> k;
        int start_idx;
        if(d == 0)
        {
            start_idx = m - k + 1;
        }
        else
        {
            start_idx = 1 + k;
        }
        
        for(int i = x; i <= n; i += x)
        {
            int tmp[m + 1];
            std::memcpy(tmp, circle[i], sizeof(tmp));
            int cnt = 1;
            for(int j = start_idx; j <= m; j++)
            {
                circle[i][cnt++] = tmp[j];
            }
            for(int j = 1; j < start_idx; j++)
            {
                circle[i][cnt++] = tmp[j];
            }
        }
        bool FLAG_DELETED = false;
        
        std::queue<std::pair<int, int>> q;
        std::memset(visited, 0, sizeof(visited));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(circle[i][j] == -1 || visited[i][j])
                {
                    continue;
                }
                visited[i][j] = 1;
                q.push({i, j});
                std::vector<std::pair<int, int>> list;
                while(!q.empty())
                {
                    std::pair<int, int> front = q.front();
                    int x = front.first;
                    int y = front.second;
                    q.pop();
                    list.push_back(front);
                    for(int d = 0; d < 4; d++)
                    {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if(nx == 0 || nx == n + 1)
                        {
                            continue;
                        }
                        if(ny == 0)
                        {
                            ny = m;
                        }
                        if(ny == m + 1)
                        {
                            ny = 1;
                        }
                        if(visited[nx][ny] || circle[nx][ny] == -1 || circle[x][y] != circle[nx][ny])
                        {
                            continue;
                        }
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                if(list.size() == 1)
                {
                    visited[list[0].first][list[0].second] = 0;
                    continue;
                }
                for(auto x : list)
                {
                    FLAG_DELETED = true;
                    circle[x.first][x.second] = -1;
                }
            }
        }
        if(!FLAG_DELETED)
        {
            double sum = 0;
            int cnt = 0;
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= m; j++)
                {
                    if(circle[i][j] == -1)
                    {
                        continue;
                    }
                    cnt++;
                    sum += circle[i][j];
                }
            }
            if(cnt == 0)
            {
                break;
            }
            sum /= cnt;
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= m; j++)
                {
                    if(circle[i][j] == -1)
                    {
                        continue;
                    }
                    if(circle[i][j] > sum)
                    {
                        circle[i][j]--;
                    }
                    else if(circle[i][j] < sum)
                    {
                        circle[i][j]++;
                    }
                }
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(circle[i][j] == -1)
            {
                continue;
            }
            sum += circle[i][j];
        }
    }
    std::cout << sum << '\n';
    return 0;
}
