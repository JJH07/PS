//
//  main.cpp
//  3034
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, w, h, p;
    
    std::cin >> n >> w >> h;
    
    for(int i = 0; i < n; i++)
    {
        std::cin >> p;
        w * w + h * h >= p * p ? std::cout << "DA\n" : std::cout << "NE\n";
    }
    
    return 0;
}
