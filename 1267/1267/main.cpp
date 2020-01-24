//
//  main.cpp
//  1267
//
//  Created by 진준호 on 2020/01/07.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, Y = 0, M = 0;
    
    std::cin >> n;
    
    while(n--)
    {
        int tmp;
        std::cin >> tmp;
        Y += (tmp / 30 + 1) * 10;
        M += (tmp / 60 + 1) * 15;
    }
    if(Y > M)
    {
        std::cout << "M " << M << '\n';
    }
    else if(Y < M)
    {
        std::cout << "Y " << Y << '\n';
    }
    else
    {
        std::cout << "Y M " << Y << '\n';
    }
    return 0;
}
