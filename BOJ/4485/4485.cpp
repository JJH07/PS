//
//  main.cpp
//  4485
//
//  Created by 진준호 on 2020/05/15.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

struct node{
    int x;
    int y;
    int steal;
};
bool operator <(const node& x, const node& y)
{
    return std::tie(x.steal, x.x, x.y) > std::tie(y.steal, y.x, y.y);
}
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int map[126][126], distance[126][126], testcase = 1;
    std::priority_queue<node> pq;
    
    while(testcase++)
    {
        int n;
        std::cin >> n;
        if(n == 0)
        {
            break;
        }

        std::fill(distance[0], distance[0] + 126 * 126, n * n * 10);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                std::cin >> map[i][j];
            }
        }

        distance[0][0] = map[0][0];
        pq.push({0, 0, map[0][0]});
        while(!pq.empty())
        {
            node top = pq.top();
            pq.pop();
            int x = top.x;
            int y = top.y;
            int dist = top.steal;
            if(distance[x][y] < dist)
            {
                continue;
            }
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                {
                    continue;
                }
                int ndist = map[nx][ny] + dist;
                if(ndist < distance[nx][ny])
                {
                    distance[nx][ny] = ndist;
                    pq.push({nx, ny, ndist});
                }
            }
        }
        std::cout << "Problem " << testcase - 1 << ": " << distance[n - 1][n - 1] << '\n';
    }

    return 0;
}
