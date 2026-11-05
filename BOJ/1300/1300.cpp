//
//  main.cpp
//  1300
//
//  Created by 진준호 on 2019/12/26.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>

long long n, k;
long long binary(long long l, long long r)
{
    if(l > r)
    {
        return l;
    }
    long long mid = (l + r) / 2;
    long long cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        cnt += (n > (mid / i) ? mid / i : n);
    }
    if(cnt < k)
    {
        return binary(mid + 1, r);
    }
    else
    {
        return binary(l, mid - 1);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> k;
    std::cout << binary(1, k) << '\n';
    
    return 0;
}
