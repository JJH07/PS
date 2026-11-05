//
//  main.cpp
//  10707
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int A, B, C, D, P;
    
    std::cin >> A >> B >> C >> D >> P;
    
    std::cout << std::min(P * A, (B + (P - C > 0 ? (P - C) * D : 0)));
    
    return 0;
}
