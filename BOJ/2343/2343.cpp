//
//  main.cpp
//  2343
//
//  Created by 진준호 on 2020/05/22.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    std::cin >> n >> m;
    std::vector<long long> list(n);
    long long s = 0, e = 0;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
        s = std::max(s, list[i]);
        e += list[i];
    }
    while(s <= e)
    {
        long long mid = (s + e) / 2;
        
        int count = 1;
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += list[i];
            if(sum > mid)
            {
                sum = list[i];
                count++;
            }
        }
        if(count <= m)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    std::cout << s << '\n';

    return 0;
}
