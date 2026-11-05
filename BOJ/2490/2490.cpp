//
//  main.cpp
//  2490
//
//  Created by 진준호 on 2020/01/21.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < 3; i++)
    {
        int ans = 0;
        for(int j = 0; j < 4; j++)
        {
            int t;
            std::cin >> t;
            if(t == 0)
            {
                ans++;
            }
        }
        if(ans)
        {
            std::cout << (char('A'+ ans - 1)) << '\n';
        }
        else
        {
            std::cout << "E\n";
        }
    }
    
    return 0;
}
