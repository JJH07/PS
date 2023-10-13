//
//  main.cpp
//  14891
//
//  Created by 진준호 on 2020/03/25.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int spin[4][8], left[4], right[4], rotate_table[4];
    int k;

    for(int i = 0; i < 4; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        for(int j = 0; j < 8; j++)
        {
            if(tmp[j] == '0')
            {
                spin[i][j] = 0;
            }
            else
            {
                spin[i][j] = 1;
            }
        }
        left[i] = 6;
        right[i] = 2;
    }
    std::cin >> k;
    while(k--)
    {
        int number, way, rotate;
        std::memset(rotate_table, 0, sizeof(rotate_table));
        std::cin >> number >> way;
        number--;
        
        rotate = way * -1;
        rotate_table[number] = rotate;
        for(int i = number; i < 3; i++)
        {
            rotate *= -1;
            if(spin[i][right[i]] + spin[i + 1][left[i + 1]] != 1)
            {
                break;
            }
            rotate_table[i + 1] = rotate;
        }
        rotate = way * -1;
        for(int i = number; i > 0; i--)
        {
            rotate *= -1;
            if(spin[i][left[i]] + spin[i - 1][right[i - 1]] != 1)
            {
                break;
            }
            rotate_table[i - 1] = rotate;
        }
        for(int i = 0; i < 4; i++)
        {
            left[i] = (left[i] + 8 + rotate_table[i]) % 8;
            right[i] = (right[i] + 8 + rotate_table[i]) % 8;
        }
    }
    int ans = 0, point = 1;
    for(int i = 0; i < 4; i++)
    {
        if(spin[i][(left[i] + 2) %  8])
        {
            ans += point;
        }
        point *= 2;
    }
    std::cout << ans << '\n';
    return 0;
}
