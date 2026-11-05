//
//  main.cpp
//  17837
//
//  Created by 진준호 on 2020/04/13.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

struct horse
{
    int x;
    int y;
    int way;
};
void move(std::stack<int> &from, std::stack<int> &to, int idx)
{
    
}
int dx[5] = {0, 0, 0, -1, 1}, dy[5] = {0, 1, -1, 0, 0};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    bool FLAG = false;
    int n, k, chess_t[13][13];
    horse h[10];
    std::stack<int> stack_idx[13][13];
    
    std::cin >> n >> k;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> chess_t[i][j];
        }
    }
    for(int i = 0; i < k; i++)
    {
        std::cin >> h[i].x >> h[i].y >> h[i].way;
        stack_idx[h[i].x][h[i].y].push(i);
    }
    
    int turn = 1;

    while(turn <= 1000)
    {
        for(int i = 0; i < k; i++)
        {
            int nx = h[i].x + dx[h[i].way];
            int ny = h[i].y + dy[h[i].way];
            if(nx < 1 || ny < 1 || nx > n || ny > n || chess_t[nx][ny] == 2)
            {
                if(h[i].way % 2 == 1)
                {
                    h[i].way++;
                }
                else
                {
                    h[i].way--;
                }
                nx = h[i].x + dx[h[i].way];
                ny = h[i].y + dy[h[i].way];
                if(nx < 1 || ny < 1 || nx > n || ny > n || chess_t[nx][ny] == 2)
                {
                    continue;
                }
            }
            std::stack<int> &from = stack_idx[h[i].x][h[i].y];
            std::stack<int> &to = stack_idx[nx][ny];
            std::vector<int> list;
            while(!from.empty())
            {
                int top = from.top();
                from.pop();
                h[top].x = nx;
                h[top].y = ny;
                list.push_back(top);
                if(top == i)
                {
                    break;
                }
            }
            if(list.size() + to.size() >= 4)
            {
                FLAG = true;
                break;
            }
            if(chess_t[nx][ny] == 1)
            {
                for(int li : list)
                {
                    to.push(li);
                }
            }
            else
            {
                reverse(list.begin(), list.end());
                for(int li : list)
                {
                    to.push(li);
                }
            }
        }
        if(FLAG)
        {
            break;
        }
        turn++;
    }
    if(turn == 1001)
    {
        std::cout << "-1\n";
    }
    else
    {
        std::cout << turn << '\n';
    }
    return 0;
}
