//
//  main.cpp
//  2935
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string A, B;
    char op;
    
    std::cin >> A >> op >> B;
    if(op == '*')
    {
        std::cout << '1';
        for(int i = 0; i < (int)(A.length() + B.length() - 2); i++)
        {
            std::cout << '0';
        }
    }
    else
    {
        for(int i = std::max((int)A.length(), (int)B.length()); i > 0; i--)
        {
            int cnt = 0;
            if(i == (int)A.length())
            {
                cnt++;
            }
            if(i == (int)B.length())
            {
                cnt++;
            }
            std::cout << cnt;
        }
    }
    
    return 0;
}
