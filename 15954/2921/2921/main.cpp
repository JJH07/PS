//
//  main.cpp
//  2921
//
//  Created by 진준호 on 2020/01/07.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, sum = 0;
    std::cin >> N;
    
    for(int i = 1; i <= N; i++)
    {
        sum += i * (i + 1) + (i * (i + 1)) / 2;
    }
    std::cout << sum << '\n';
    return 0;
}
