//
//  main.cpp
//  17401
//
//  Created by 진준호 on 2020/05/15.
//  Copyright © 2020 진준호. All rights reserved.
//
#include <iostream>
#include <vector>

typedef long long ll;
typedef std::vector<std::vector<ll>> matrix;
const ll MOD = 1000000007;

matrix operator *(const matrix &x, const matrix &y)
{
    int n = (int)x.size() - 1;
    matrix ret(n + 1, std::vector<ll>(n + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int k = 1; k <= n; k++)
        {
            ll val = x[i][k];
            if(val == 0)
            {
                continue;
            }
            for(int j = 1; j <= n; j++)
            {
                ret[i][j] = (ret[i][j] + val * y[k][j]) % MOD;
            }
        }
    }
    return ret;
}
matrix power_of_N(matrix a, int n)
{
    int size = (int)a.size() - 1;
    matrix ret(size + 1, std::vector<ll>(size + 1, 0));
    for(int i = 1; i <= size; i++)
    {
        ret[i][i] = 1;
    }
    while(n > 0)
    {
        if(n % 2)
        {
            ret = ret * a;
        }
        a = a * a;
        n /= 2;
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t, n, d;
    std::cin >> t >> n >> d;
    std::vector<matrix> v(t + 1, matrix(n + 1, std::vector<ll>(n + 1, 0)));

    for(int i = 1; i <= t; i++)
    {
        int m;
        std::cin >> m;
        for(int j = 0; j < m; j++)
        {
            int a, b;
            ll c;
            std::cin >> a >> b >> c;
            v[i][a][b] = c;
        }
    }

    matrix ans(n + 1, std::vector<ll>(n + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        ans[i][i] = 1;
    }

    for(int i = 2; i <= t; i++)
    {
        v[i] = v[i - 1] * v[i];
    }

    ans = ans * power_of_N(v[t], d / t);
    if(d % t > 0)
    {
        ans = ans * v[d % t];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
