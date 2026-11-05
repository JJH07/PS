//
//  main.cpp
//  1297
//
//  Created by 진준호 on 2020/01/07.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cmath>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int screen, h, w;
    
    std::cin >> screen >> h >> w;
    
    std::cout << (int)(screen * h / sqrt(h * h + w * w)) << ' ' << (int)(screen * w / sqrt(h * h + w * w)) << '\n';
    return 0;
}
