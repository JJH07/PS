//
//  main.cpp
//  5532
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int L, A, B, C, D;
    std::cin >> L >> A >> B >> C >> D;
    std::cout << L - std::max((A / C + (A % C ? 1 : 0)), (B / D + (B % D ? 1 : 0)));
    
    return 0;
}
