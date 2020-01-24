//
//  main.cpp
//  9506
//
//  Created by 진준호 on 2019/12/31.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    while(1)
    {
        std::cin >> n;
        if(n == -1)
        {
            break;
        }
        std::vector<int> list;
        int sum = 1;
        list.push_back(1);
        for(int i = 2; i <= (int)sqrt(n); i++)
        {
            if(n % i)
            {
                continue;
            }
            sum += i;
            list.push_back(i);
            if(i != n % i)
            {
                sum += n / i;
                list.push_back(n / i);
            }
        }
        sort(list.begin(), list.end());
        if(sum == n)
        {
            std::cout << n << " = ";
            for(std::vector<int>::iterator it = list.begin(); it != list.end(); it++)
            {
                if(it != list.begin())
                {
                    std::cout << "+ ";
                }
                std::cout << *it << ' ';
            }
            std::cout << '\n';
        }
        else
        {
            std::cout << n << " is NOT perfect.\n";
        }
    }
    return 0;
}
