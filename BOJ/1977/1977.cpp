//
//  main.cpp
//  1977
//
//  Created by 진준호 on 2019/12/27.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int m, n, sum = 0, min_v = 10001;
    std::vector<int> list;
    
    for(int i = 1; i <= 100; i++)
    {
        list.push_back(i * i);
    }
    
    std::cin >> m >> n;
    
    for(std::vector<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        if(*it > n)
        {
            break;
        }
        if(*it >= m && *it <= n)
        {
            min_v = std::min(min_v, *it);
            sum +=  *it;
        }
    }
    if(min_v != 10001)
    {
        std::cout << sum << '\n' << min_v << '\n';
    }
    else
    {
        std::cout << -1 << '\n';
    }
    return 0;
}
