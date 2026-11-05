//
//  main.cpp
//  1764
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::set<std::string> n_list;
    std::string name;
    std::vector<std::string> nm_list;
    
    std::cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        std::cin >> name;
        n_list.insert(name);
    }
    for(int i = 0; i < m; i++)
    {
        std::cin >> name;
        if(n_list.find(name) != n_list.end())
        {
            nm_list.push_back(name);
        }
    }
    sort(nm_list.begin(), nm_list.end());
    
    std::cout << (int)nm_list.size() << '\n';
    for(std::vector<std::string>::iterator it = nm_list.begin(); it != nm_list.end(); it++)
    {
        std::cout << *it << '\n';
    }
    
    return 0;
}
