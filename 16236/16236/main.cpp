//
//  main.cpp
//  16236
//
//  Created by 진준호 on 2020/04/06.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

struct nd{
    int x;
    int y;
    int distance;
};
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};

bool comp(const nd &a, const nd &b)
{
    if(a.distance == b.distance)
    {
        if(a.x == b.x)
        {
            return a.y < b.y;
        }
        return a.x < b.x;
    }
    return a.distance < b.distance;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, map[21][21], x, y, shark_sz = 2, eaten = 0, second = 0;
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> map[i][j];
            if(map[i][j] == 9)
            {
                map[i][j] = 0;
                x = i;
                y = j;
            }
        }
    }
    
    while(1)
    {
        std::queue<nd> q;
        std::vector<nd> eatable_fish;
        int visited[n][n];
        
        std::memset(visited, 0, sizeof(visited));
        
        visited[x][y] = 1;
        q.push({x, y, 0});
        while(!q.empty())
        {
            nd front =  q.front();
            q.pop();
            
            if(map[front.x][front.y] > 0 && shark_sz > map[front.x][front.y])
            {
                eatable_fish.push_back(front);
            }
            for(int i = 0; i < 4; i++)
            {
                int nx = front.x + dx[i];
                int ny = front.y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny] || map[nx][ny] > shark_sz)
                {
                    continue;
                }
                visited[nx][ny] = 1;
                q.push({nx, ny, front.distance + 1});
            }
        }
        if((int)eatable_fish.size() == 0)
        {
            break;
        }
        std::sort(eatable_fish.begin(), eatable_fish.end(), comp);
        nd next = eatable_fish[0];
        second += next.distance;
        eaten++;
        if(eaten == shark_sz)
        {
            eaten = 0;
            shark_sz++;
        }
        x = next.x;
        y = next.y;
        map[x][y] = 0;
    }
    std::cout << second << '\n';
    return 0;
}
