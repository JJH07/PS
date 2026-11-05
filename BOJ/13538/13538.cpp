//
//  main.cpp
//  13538
//
//  Created by 진준호 on 2020/04/27.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int m;
    std::vector<int> list;

    std::cin >> m;
    for(int i = 0; i < m; i++)
    {
        int op, x;
        std::cin >> op;
        if(op == 1)
        {
            std::cin >> x;
            list.push_back(x);
        }
        else if(op == 2)
        {
            int L, R;
            std::cin >> L >> R >> x;
            
        }
        else if(op == 3)
        {
            int k;
            std::cin >> k;
            while(!list.empty() && k > 0)
            {
                list.pop_back();
                k--;
            }
        }
        else if(op == 4)
        {
            int L, R;
            std::cin >> L >> R >> x;
            
        }
        else
        {
            int L, R, k;
            std::cin >> L >> R >> k;
            
        }
    }
    
    return 0;
}
