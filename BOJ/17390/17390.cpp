//
//  main.cpp
//  17390
//
//  Created by 진준호 on 2020/05/03.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, q;
    std::vector<int> list;
    std::cin >> n >> q;
    list.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        int number;
        std::cin >> number;
        list.push_back(number);
    }
    std::sort(list.begin(), list.end());
    for(int i = 1; i <= n; i++)
    {
        list[i] = list[i] + list[i - 1];
    }
    for(int i = 0; i < q; i++)
    {
        int l, r;
        std::cin >> l >> r;
        std::cout << list[r] - list[l - 1] << '\n';
    }
    
    return 0;
}
