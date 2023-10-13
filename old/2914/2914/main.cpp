//
//  main.cpp
//  2914
//
//  Created by 진준호 on 2019/12/27.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <cmath>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int a, i;
    
    std::cin >> a >> i;
    
    std::cout << a * (i - 1) + 1 << '\n';
    
    return 0;
}
