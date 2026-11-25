// Copyright © 2019 진준호. All rights reserved.

#include <algorithm>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, k;
    std::cin >> n >> k;
    long long left = 1, right = k;
    while(left < right)
    {
        const long long mid = left + (right - left) / 2;
        long long count = 0;
        for(long long row = 1; row <= n && count < k; row++)
        {
            count += std::min(n, mid / row);
        }
        if(count < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    std::cout << left << '\n';
    return 0;
}
