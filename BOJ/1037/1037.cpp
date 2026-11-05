//
//  main.cpp
//  1037
//
//  Created by 진준호 on 2019/12/27.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int c, tmp;
    std::vector<int> list;
    
    std::cin >> c;
    for(int i = 0; i < c; i++)
    {
        std::cin >> tmp;
        list.push_back(tmp);
    }
    int size = (int)list.size();
    
    std::sort(list.begin(), list.end());
    std::cout << list[0] * list[size - 1] << '\n';
    
    return 0;
}
