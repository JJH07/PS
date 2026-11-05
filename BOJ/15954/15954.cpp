//
//  main.cpp
//  15954
//
//  Created by 진준호 on 2019/11/26.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
long double ans = 1234567.1111;
void get_p(std::vector<long double> &list, int s, int e, int k)
{
    long double sum = 0.0, avg, p;
    int cnt = k;
    for(int i = s; i < s + k - 1; i++)
    {
        sum += list[i];
    }
    for(int i = s + k - 1; i < e; i++)
    {
        sum += list[i];
        
        avg = sum / cnt;
        p = 0.0;
        for(int j = s; j <= i; j++)
        {
            p += pow((list[j] - avg), 2);
        }
        p = sqrt(p / cnt);
        if(ans > p)
        {
            ans = p;
        }
        cnt++;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.precision(11);
    
    int n, k, tmp;
    std::vector<long double> list;
    
    std::cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        std::cin >> tmp;
        list.push_back(tmp);
    }
    for(int i = 0; i <= n - k; i++)
    {
        get_p(list, i, n, k);
    }
    std::cout << ans << '\n';
    return 0;
}
