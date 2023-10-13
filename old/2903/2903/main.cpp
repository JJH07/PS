//
//  main.cpp
//  2903
//
//  Created by 진준호 on 2020/01/07.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, p = 2;
    std::cin >> N;
    for(int i = 1; i <= N; i++)
    {
        p += p - 1;
    }
    std::cout << p * p << '\n';
    
    return 0;
}
