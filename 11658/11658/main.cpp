//
//  main.cpp
//  11658
//
//  Created by 진준호 on 2020/04/20.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>

long long list[1025][1025];
long long tree[1025][1025];
int n, m;

long long sum(int i, int j)
{
    long long ans = 0;
    for(int x = i; x > 0; x -= (x & -x))
    {
        for(int y = j; y > 0; y -= (y & -y))
        {
            ans += tree[x][y];
        }
    }
    return ans;
}
void update(int i, int j, long long diff)
{
    for(int x = i; x <= n; x += (x & -x))
    {
        for(int y = j; y <= n; y += (y & -y))
        {
            tree[x][y] += diff;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%lld", &list[i][j]);
            update(i, j, list[i][j]);
        }
    }
    for(int i = 0; i < m; i++)
    {
        int w, x, y;
        scanf("%d %d %d", &w, &x, &y);
        if(w == 0)
        {
            long long c;
            scanf("%lld", &c);
            update(x, y, c - list[x][y]);
            list[x][y] = c;
        }
        else
        {
            int x2, y2;
            scanf("%d %d", &x2, &y2);
            std::cout << sum(x2, y2) - sum(x2, y - 1) - sum(x - 1, y2) + sum(x - 1, y - 1) << '\n';
        }
    }
    return 0;
}
