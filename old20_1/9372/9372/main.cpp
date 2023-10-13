//
//  main.cpp
//  9372
//
//  Created by 진준호 on 2019/11/26.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    
    int t, n, m, a, b;
    
    std::cin >> t;
    while(t--)
    {
        std::cin >> n >> m;
        for(int i = 0; i < m; i++)
        {
            std::cin >> a >> b;
        }
        std::cout << n-1 << '\n';
    }
    return 0;
}
