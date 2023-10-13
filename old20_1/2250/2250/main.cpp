//
//  main.cpp
//  2250
//
//  Created by 진준호 on 2019/12/25.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <climits>

int map[10001][2], node_val[10001][2];
bool visited[10001];
int finding_root(int n)
{
    int table[n + 1], ret = -1;
    std::fill(table, table + n + 1, -1);
    for(int i = 1; i <= n; i++)
    {
        int l = map[i][0];
        int r = map[i][1];
        if(l != -1)
        {
            table[l] = 1;
        }
        if(r != -1)
        {
            table[r] = 1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(table[i] == -1)
        {
            ret = i;
            break;
        }
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, num, counting = 1;
    int max_width = -1, max_idx;
    std::stack<std::pair<int, int>> stk;
    
    std::cin >> n;
    
    for(int i = 1; i <= 10000; i++)
    {
        node_val[i][0] = INT_MAX;
        node_val[i][1] = INT_MIN;
    }
    for(int i = 0; i < n; i++)
    {
        std::cin >> num >> map[num][0] >> map[num][1];
    }
    int root = finding_root(n);
    stk.push(std::make_pair(root, 1));
    visited[root] = true;
    while(!stk.empty())
    {
        std::pair<int, int> top = stk.top();
        int cur_n = top.first;
        int cur_lv = top.second;
        int left = map[cur_n][0];
        int right = map[cur_n][1];
        if(left != -1 && !visited[left])
        {
            stk.push(std::make_pair(left, cur_lv + 1));
            visited[left] = true;
            continue;
        }
        node_val[cur_lv][0] = std::min(node_val[cur_lv][0], counting);
        node_val[cur_lv][1] = std::max(node_val[cur_lv][1], counting);
        stk.pop();
        counting++;
        if(right != -1 && !visited[right])
        {
            stk.push(std::make_pair(right, cur_lv + 1));
            visited[right] = true;
        }
    }
    for(int i = 1; i <= 10000; i++)
    {
        if(node_val[i][0] == INT_MAX)
        {
            break;
        }
        int width = node_val[i][1] - node_val[i][0] + 1;
        if(width > max_width)
        {
            max_width = width;
            max_idx = i;
        }
    }
    std::cout << max_idx << ' ' << max_width << '\n';
    return 0;
}
