//
//  main.cpp
//  5533
//
//  Created by 진준호 on 2020/01/29.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, table[201][3], card_used[3][101];
    
    std::fill(card_used[0], card_used[0] + 3 * 101, 0);
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> table[i][0] >> table[i][1] >> table[i][2];
        card_used[0][table[i][0]]++;
        card_used[1][table[i][1]]++;
        card_used[2][table[i][2]]++;
    }
    for(int i = 0; i < n; i++)
    {
        int points = 0;
        for(int j = 0; j < 3; j++)
        {
            points += (card_used[j][table[i][j]] > 1 ? 0 : table[i][j]);
        }
        std::cout << points << '\n';
    }
    return 0;
}
