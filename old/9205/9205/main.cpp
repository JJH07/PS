//
//  main.cpp
//  9205
//
//  Created by 진준호 on 2019/12/04.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <queue>

int n;
struct pos{
    int x;
    int y;
};
pos home, store[101];

inline int get_distance(pos p, pos q)
{
    return abs(p.x - q.x) + abs(p.y - q.y);
}
bool go()
{
    int visited[101];
    std::fill(visited, visited + 101, 0);
    
    std::queue<pos> q;
    pos front = home;
    
    q.push(front);
    while(!q.empty())
    {
        if(visited[n] == 1)
        {
            return true;
        }
        front = q.front();
        q.pop();
        for(int i = 0; i <= n; i++)
        {
            if(visited[i] == 0 && get_distance(store[i], front) <= 1000)
            {
                q.push(store[i]);
                visited[i] = 1;
            }
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n >> home.x >> home.y;
        for(int i = 0; i <= n; i++)
        {
            std::cin >> store[i].x >> store[i].y;
        }
        if(go())
        {
            std::cout << "happy\n";
        }
        else
        {
            std::cout << "sad\n";
        }
    }
    
    return 0;
}
