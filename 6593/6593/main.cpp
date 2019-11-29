//
//  main.cpp
//  6593
//
//  Created by 진준호 on 2019/11/29.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>

int L, R, C, visited[31][31][31];
char map[31][31][31];
int dr[6] = {1, 0, -1, 0, 0, 0}, dc[6] = {0, 1, 0, -1, 0, 0}, dl[6] = {0, 0, 0, 0, 1, -1};
struct node{
    int l;
    int r;
    int c;
    int dist;
};
node front;
std::queue<node> q;

int escape()
{
    while(!q.empty())
    {
        front = q.front();
        q.pop();
        if(map[front.l][front.r][front.c] == 'E')
        {
            while(!q.empty())
            {
                q.pop();
            }
            return front.dist;
        }
        for(int i = 0; i < 6; i++)
        {
            int nl = front.l + dl[i];
            int nr = front.r + dr[i];
            int nc = front.c + dc[i];
            if(nl < 0 || nr < 0 || nc < 0 || nl >= L || nr >= R || nc >= C || visited[nl][nr][nc] == 1)
            {
                continue;
            }
            visited[nl][nr][nc] = 1;
            q.push({nl, nr, nc, front.dist + 1});
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    
    while(1)
    {
        std::cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0)
        {
            break;13
        }
        for(int i = 0; i < L; i++)
        {
            for(int j = 0; j < R; j++)
            {
                for(int k = 0; k < C; k++)
                {
                    std::cin >> map[i][j][k];
                    if(map[i][j][k] == 'S')
                    {
                        q.push({i, j, k, 0});
                        visited[i][j][k] = 1;
                    }
                    else if(map[i][j][k] == '#')
                    {
                        visited[i][j][k] = 1;
                    }
                    else
                    {
                        visited[i][j][k] = 0;
                    }
                }
            }
        }
        int ans;
        if((ans = escape()) > -1)
        {
            std::cout << "Escaped in " << ans << " minute(s).\n";
        }
        else
        {
            std::cout << "Trapped!\n";
        }
    }
    
    return 0;
}
