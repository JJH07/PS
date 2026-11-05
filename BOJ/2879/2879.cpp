//
//  main.cpp
//  2879
//
//  Created by 진준호 on 2020/02/27.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <stack>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, now[1000], ans[1000], cnt = 0;
    
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cin >> now[i];
    }
    for(int i = 0; i < n; i++)
    {
        std::cin >> ans[i];
    }
    for(int i = 0; i < n; i++)
    {
        while(now[i] != ans[i])
        {
            cnt++;
            int plus_minus = ans[i] - now[i];
            std::stack<int> stk;
            for(int j = i; j < n; j++)
            {
                if(plus_minus * (ans[j] - now[j]) <= 0)
                {
                    break;
                }
                stk.push(j);
            }
            while(!stk.empty())
            {
                int top = stk.top();
                stk.pop();
                if(plus_minus > 0)
                {
                    now[top]++;
                }
                else
                {
                    now[top]--;
                }
            }
        }
    }
    std::cout << cnt << '\n';
    return 0;
}
