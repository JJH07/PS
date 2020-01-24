//
//  main.cpp
//  3049
//
//  Created by 진준호 on 2020/01/15.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N;
    std::cin >> N;
    std::cout << N * (N-1) * (N-2) * (N-3) / 24 << '\n';
    
    return 0;
}
