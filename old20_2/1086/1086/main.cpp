//
//  main.cpp
//  1086
//
//  Created by 진준호 on 2020/05/17.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>

int n, k;
long long memo[101][1 << 15], mod_10[51], number_len[51], number_mod[15];
std::string list[15];
long long gcd(long long a, long long b)
{
    if(b > a)
    {
        return gcd(b, a);
    }
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
long long solve(int rest, int visited)
{
    if(visited == (1 << n) - 1)
    {
        return rest == 0 ? 1 : 0;
    }
    long long &ret = memo[rest][visited];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    for(int i = 0; i < n; i++)
    {
        if(!(visited & (1 << i)))
        {
            ret += solve(((rest * mod_10[number_len[i]] + number_mod[i]) % k), visited + (1 << i));
        }
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::fill(memo[0], memo[0] + (101 * ((1 << 15) - 1)), -1);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
        number_len[i] = list[i].length();
    }
    std::cin >> k;

    mod_10[0] = 1 % k;
    for(int i = 1; i <= 50; i++)
    {
        mod_10[i] = (mod_10[i - 1] * 10) % k;
    }
    for(int i = 0; i < n; i++)
    {
        long long ret = 0;
        for(auto x : list[i])
        {
            ret = (ret * 10 + (x - '0')) % k;
        }
        number_mod[i] = ret;
    }

    long long ans = solve(0, 0);
    long long max_ = 1;
    for(long long i = 1; i <= n; i++)
    {
        max_ *= i;
    }

    if(ans == 0)
    {
        std::cout << "0/1\n";
    }
    else
    {
        long long gcd_ = gcd(ans, max_);
        if(gcd_ > 0)
        {
            ans /= gcd_;
            max_ /= gcd_;
        }
        std::cout << ans << '/' << max_ << '\n';
    }
    return 0;
}
