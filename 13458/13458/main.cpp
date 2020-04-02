//
//  main.cpp
//  13458
//
//  Created by 진준호 on 2020/03/16.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, b, c;
    std::vector<int> center;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        center.push_back(tmp);
    }
    std::cin >> b >> c;
    unsigned long long cnt = 0;
    for(auto x : center)
    {
        cnt++;
        x -= b;
        if(x <= 0)
        {
            continue;
        }
        cnt += (x + c - 1) / c;
    }
    std::cout << cnt << '\n';
    return 0;
}
