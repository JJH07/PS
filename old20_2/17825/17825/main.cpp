//
//  main.cpp
//  17825
//
//  Created by 진준호 on 2020/04/16.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>

int gameboard[41], points[41], number[10], horse[4], ans;

void dfs(int idx, int sum)
{
    for(int i = 0; i < 4; i++)
    {
        if(horse[i] == 0 || horse[i] == -1)
        {
            continue;
        }
        for(int j = i + 1; j < 4; j++)
        {
            if(horse[i] == horse[j])
            {
                return ;
            }
        }
    }
    if(idx == 10)
    {
        ans = std::max(ans, sum);
        return ;
    }
    for(int i = 0; i < 4; i++)
    {
        if(horse[i] == -1)
        {
            continue;
        }
        int temp = horse[i], keep = horse[i];
        int len = number[idx];
        if(temp == 5)
        {
            temp = 21;
            len--;
        }
        else if(temp == 10)
        {
            temp = 27;
            len--;
        }
        else if(temp == 15)
        {
            temp = 24;
            len--;
        }
        for(int j = 0; j < len; j++)
        {
            if(temp == -1)
            {
                break;
            }
            temp = gameboard[temp];
        }
        horse[i] = temp;
        dfs(idx + 1, sum + (temp != -1 ? points[temp] : 0));
        horse[i] = keep;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for(int i = 0; i < 20; i++)
    {
        gameboard[i] = i + 1;
        points[i] = i * 2;
    }
    
    gameboard[20] = -1;
    points[20] = 40;
    
    gameboard[21] = 22;
    points[21] = 13;
    gameboard[22] = 23;
    points[22] = 16;
    gameboard[23] = 29;
    points[23] = 19;
    
    gameboard[24] = 25;
    points[24] = 28;
    gameboard[25] = 26;
    points[25] = 27;
    gameboard[26] = 29;
    points[26] = 26;
    
    gameboard[27] = 28;
    points[27] = 22;
    gameboard[28] = 29;
    points[28] = 24;
    
    gameboard[29] = 30;
    points[29] = 25;
    gameboard[30] = 31;
    points[30] = 30;
    gameboard[31] = 20;
    points[31] = 35;
    
    for(int i = 0; i < 10; i++)
    {
        std::cin >> number[i];
    }
    dfs(0, 0);
    std::cout << ans << '\n';
    return 0;
}
