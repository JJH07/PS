//
//  main.cpp
//  17393
//
//  Created by 진준호 on 2020/05/05.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    std::vector<unsigned long long> a(n), b(n);
    
    for(int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        std::vector<unsigned long long>::iterator lit = std::upper_bound(b.begin() + i, b.end(), a[i]);
        std::cout << lit - b.begin() - i - 1 << ' ';
    }
    std::cout << "0\n";
    return 0;
}
