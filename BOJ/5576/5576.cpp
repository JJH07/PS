//
//  main.cpp
//  5576
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>

bool compare(const int &x, const int &y)
{
    return x > y;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<int> w, k;
    int score;
    for(int i = 0; i < 10; i++)
    {
        std::cin >> score;
        w.push_back(score);
    }
    for(int i = 0; i < 10; i++)
    {
        std::cin >> score;
        k.push_back(score);
    }
    std::sort(w.begin(), w.end(), compare);
    std::sort(k.begin(), k.end(), compare);
    
    std::cout << w[0] + w[1] + w[2] << ' ' << k[0] + k[1] + k[2] << '\n';
    
    return 0;
}
