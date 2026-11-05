//
//  main.cpp
//  2851
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cmath>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int mushroom, ans = 1000, tot = 0;
    for(int i = 0; i < 10; i++)
    {
        std::cin >> mushroom;
        tot += mushroom;
        ans = abs(ans - 100) > abs(tot - 100) ? tot : ans;
    }
    std::cout << ans << '\n';
    
    return 0;
}
