//
//  main.cpp
//  1076
//
//  Created by 진준호 on 2019/12/27.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::map<std::string, std::pair<int, long long>> list = {{"black", {0, 1}}, {"brown", {1, 10}}, {"red", {2, 100}}, {"orange", {3, 1000}}, {"yellow", {4, 10000}}, {"green", {5, 100000}}, {"blue", {6, 1000000}}, {"violet", {7, 10000000}}, {"grey", {8, 100000000}}, {"white", {9, 1000000000}}};
    
    std::string a, b, c;
    std::cin >> a >> b >> c;
    std::cout << list[c].second * (10 * list[a].first + list[b].first) << '\n';
    return 0;
}
