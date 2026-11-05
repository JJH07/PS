//
//  main.cpp
//  2407
//
//  Created by 진준호 on 2019/12/30.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
struct number{
    int len;
    int number[16];
};
number list[101][101];
void get(int n, int m)
{
    if(n == m || n == 0 || m == 0)
    {
        list[n][m].len = 1;
        list[n][m].number[0] = 1;
    }
    else
    {
        number &p = list[n-1][m-1];
        number &q = list[n-1][m];
        number &now = list[n][m];
        now.len = std::max(p.len, q.len);
        for(int i = 0; i < now.len; i++)
        {
            int v = (p.number[i] + q.number[i] + now.number[i]);
            now.number[i] = v % 10000000;
            now.number[i+1] += v / 10000000;
        }
        if(now.number[now.len] > 0)
        {
            now.len++;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, m, size;
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            get(i, j);
        }
    }
    size = list[n][m].len;
    if(size == 1)
    {
        printf("%d", list[n][m].number[0]);
    }
    else
    {
        printf("%d", list[n][m].number[size - 1]);
        for(int k = size - 2; k >= 0; k--)
        {
            printf("%07d", list[n][m].number[k]);
        }
    }
    printf("\n");
    return 0;
}
