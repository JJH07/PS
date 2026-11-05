//
//  main.cpp
//  5597
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int map[31], submit;
    std::fill(map, map + 31, 0);
    
    for(int i = 0; i < 28; i++)
    {
        std::cin >> submit;
        map[submit] = 1;
    }
    for(int i = 1;  i < 31; i++)
    {
        if(map[i] == 0)
        {
            std::cout << i << '\n';
        }
    }
    return 0;
}
