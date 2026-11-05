//
//  main.cpp
//  2863
//
//  Created by 진준호 on 2020/01/15.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <climits>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double table[2][2], val[5], swap, max_v = INT_MIN;
    
    std::cin >> table[0][0] >> table[0][1] >> table[1][0] >> table[1][1];
    
    val[0] = table[0][0] / table[1][0] + table[0][1] / table[1][1];
    val[1] = table[1][0] / table[1][1] + table[0][0] / table[0][1];
    val[2] = table[1][1] / table[0][1] + table[1][0] / table[0][0];
    val[3] = table[0][1] / table[0][0] + table[1][1] / table[1][0];
    
    for(int i = 0; i < 4; i++)
    {
        if(val[i] > max_v)
        {
            swap = i;
            max_v = val[i];
        }
    }
    std::cout << swap << '\n';
    return 0;
}
