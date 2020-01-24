//
//  main.cpp
//  2798
//
//  Created by 진준호 on 2020/01/21.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, sum, ans = -1, list[101];
    
    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = i + 1; j < n - 1; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                sum = list[i] + list[j] + list[k];
                if(sum == m)
                {
                    std::cout << sum << '\n';
                    return 0;
                }
                if(sum < m)
                {
                    ans = std::max(ans, sum);
                }
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}
