//
//  main.cpp
//  17388
//
//  Created by 진준호 on 2020/05/03.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int s, k, h;
    
    std::cin >> s >> k >> h;
    if(s + k + h >= 100)
    {
        std::cout << "OK\n";
    }
    else
    {
        std::vector<std::pair<int, std::string>> rank;
        rank.push_back({s, "Soongsil"});
        rank.push_back({k, "Korea"});
        rank.push_back({h, "Hanyang"});
        std::sort(rank.begin(), rank.end());
        std::cout << rank[0].second << '\n';
    }
    
    return 0;
}
