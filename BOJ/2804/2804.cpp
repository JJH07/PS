//
//  main.cpp
//  2804
//
//  Created by 진준호 on 2020/01/29.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string a, b;
    int len_a, len_b, idx_a, idx_b;
    
    std::cin >> a >> b;
    len_a = (int)a.length();
    len_b = (int)b.length();
    
    for(int i = 0; i < len_a; i++)
    {
        for(int j = 0; j < len_b; j++)
        {
            if(a[i] == b[j])
            {
                idx_a = i;
                idx_b = j;
                i = len_a;
                break;
            }
        }
    }
    
    for(int i = 0; i < len_b; i++)
    {
        for(int j = 0; j < len_a; j++)
        {
            if(j == idx_a)
            {
                std::cout << b[i];
            }
            else if(i == idx_b)
            {
                std::cout << a[j];
            }
            else
            {
                std::cout << '.';
            }
        }
        std::cout << '\n';
    }
    return 0;
}
