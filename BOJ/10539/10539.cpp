//
//  main.cpp
//  10539
//
//  Created by 진준호 on 2020/01/29.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, num[101], temp;
    num[0] = 0;
    
    std::cin >> N;
    
    for(int i = 1; i <= N; i++)
    {
        std::cin >> temp;
        num[i] = temp * i;
    }
    for(int i = 1; i <= N; i++)
    {
        std::cout << num[i] - num[i - 1] << ' ';
    }
    return 0;
}
