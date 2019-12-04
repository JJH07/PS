//
//  main.cpp
//  1939
//
//  Created by 진준호 on 2019/12/04.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int n, m, s, e, bin_max = -1;
struct node{
    int n;
    int w;
};
std::vector<node> list[10001];

bool search(int min_arg)
{
    bool visited[n + 1];
    for(int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
    std::queue<int> q;
    int front;
    
    visited[s] = true;
    q.push(s);
    
    while(!q.empty())
    {
        front = q.front();
        q.pop();
        for(std::vector<node>::iterator it = list[front].begin(); it != list[front].end(); it++)
        {
            if(visited[it->n] == 0 && it->w >= min_arg)
            {
                visited[it->n] = true;
                q.push(it->n);
            }
        }
    }
    return visited[e];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int a, b, c;
    
    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        std::cin >> a >> b >> c;
        bin_max = std::max(bin_max, c);
        list[a].push_back({b, c});
        list[b].push_back({a, c});
    }
    std::cin >> s >> e;
    int l = 1, r = bin_max;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(search(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    std::cout << r << '\n';
    return 0;
}
