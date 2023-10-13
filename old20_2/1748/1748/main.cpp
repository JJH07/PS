//
//  main.cpp
//  1748
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int number, idx = 10, ans = 0, cnt = 1;
    
    std::cin >> number;
    
    while(idx <= number)
    {
        ans += cnt * (idx - (idx / 10));
        
        idx *= 10;
        cnt++;
    }
    ans += cnt * (number - (idx / 10) + 1);
    
    std::cout << ans << '\n';
    
    return 0;
}
