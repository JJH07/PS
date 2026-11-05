//
//  main.cpp
//  1024
//
//  Created by 진준호 on 2019/12/31.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, L, s = -1, e = -1;
    
    std::cin >> N >> L;
    
    for(int i = L; i <= N + 1; i++)
    {
        if(i > 100)
        {
            break;
        }
        if(i % 2 == 1 && N % i == 0)
        {
            s = (N / i) - i / 2;
            e = (N / i) + i / 2;
            break;
        }
        else if(i % 2 == 0 && i / 2 == N % i)
        {
            s = N / i - (i - 1) / 2;
            e = N / i + i / 2;
            break;
        }
    }
    if(s < 0)
    {
        std::cout << "-1\n";
    }
    else
    {
        for(int i = s; i <= e; i++)
        {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
    
    return 0;
}
