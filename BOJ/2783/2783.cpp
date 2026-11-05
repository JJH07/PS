//
//  main.cpp
//  2783
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    double ppg, x, y;
    std::cin >> x >> y >> n;
    ppg = x / y;
    while(n--)
    {
        std::cin >> x >> y;
        ppg = std::min(ppg, (double)x / y);
    }
    std::cout << ppg * 1000 << '\n';
    return 0;
}
