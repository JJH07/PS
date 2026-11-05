//
//  main.cpp
//  5596
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int a, b, c, d, tot;
    
    std::cin >> a >> b >> c >> d;
    tot = a + b + c + d;
    std::cin >> a >> b >> c >> d;
    
    std::cout << std::max(tot, a + b + c + d);
    
    return 0;
}
