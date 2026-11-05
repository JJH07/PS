//
//  main.cpp
//  2965
//
//  Created by 진준호 on 2019/12/30.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int x[3], ans;
    
    std::cin >> x[0] >> x[1] >> x[2];
    std::sort(x, x + 3);
    ans = std::max(x[1] - x[0], x[2] - x[1]);
    std::cout << ans - 1 << '\n';
    return 0;
}
