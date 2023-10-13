//
//  main.cpp
//  5554
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int time, sum = 0;
    
    for(int i = 0; i < 4; i++)
    {
        std::cin >> time;
        sum += time;
    }
    std::cout << sum / 60 << '\n' << sum % 60 << '\n';
    
    return 0;
}
