//
//  main.cpp
//  1159
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, check[27];
    std::string name;
    std::vector<char> list;
    
    std::fill(check, check + 27, 0);
    
    std::cin >> n;
    while(n--)
    {
        std::cin >> name;
        int idx = name[0] - 'a';
        if(check[idx] == -1)
        {
            continue;
        }
        check[idx]++;
        if(check[idx] >= 5)
        {
            list.push_back(name[0]);
            check[idx] = -1;
        }
    }
    if((int)list.empty())
    {
        std::cout << "PREDAJA\n";
    }
    sort(list.begin(), list.end());
    for(std::vector<char>::iterator it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it;
    }
    return 0;
}
