//
//  main.cpp
//  17142
//
//  Created by 진준호 on 2020/04/11.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, m, lab[50][50], virus_cnt, ans = -1;
std::vector<std::pair<int, int>> virus;
std::vector<int> list;
struct node{
    int x;
    int y;
    int dist;
};
void get_ans()
{
    std::queue<node> q;
    int visited[n][n], meet_empty_space = 0;
    std::memset(visited, 0, sizeof(visited));
    for(int idx : list)
    {
        q.push({virus[idx].first, virus[idx].second, 0});
        visited[virus[idx].first][virus[idx].second] = 1;
    }
    while(!q.empty())
    {
        node front = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = front.x + dx[i];
            int ny = front.y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny] || lab[nx][ny] == 1)
            {
                continue;
            }
            if(lab[nx][ny] == 0)
            {
                meet_empty_space = front.dist + 1;
            }
            q.push({nx, ny, front.dist + 1});
            visited[nx][ny] = front.dist + 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(lab[i][j] == 0 && visited[i][j] == 0)
            {
                return ;
            }
        }
    }
    ans = (ans > -1) ? std::min(ans, meet_empty_space) : meet_empty_space;
}
void permutation(int idx, int picked)
{
    if(picked == m)
    {
        get_ans();
        return ;
    }
    if(virus_cnt - idx < m - picked)
    {
        return ;
    }
    for(int i = idx; i < virus_cnt; i++)
    {
        list[picked] = i;
        permutation(i + 1, picked + 1);
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int tmp;
            std::cin >> tmp;
            if(tmp == 2)
            {
                virus.push_back({i, j});
            }
            lab[i][j] = tmp;
        }
    }
    virus_cnt = (int)virus.size();
    list.resize(m);
    permutation(0, 0);
    std::cout << ans << '\n';
    return 0;
}
