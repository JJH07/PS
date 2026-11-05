//
//  main.cpp
//  1652
//
//  Created by 진준호 on 2019/12/30.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
int x(std::vector<std::string> &map, int len)
{
    int cnt = 0;
    for(int i = 0; i < len; i++)
    {
        int wid = 0;
        for(int j = 0; j < len; j++)
        {
            if(map[i][j] == '.')
            {
                wid++;
            }
            else
            {
                wid >= 2 ? cnt++ : false;
                wid = 0;
            }
        }
        if(wid >= 2)
        {
            cnt++;
        }
    }
    return cnt;
}
int y(std::vector<std::string> &map, int len)
{
    int cnt = 0;
    for(int i = 0; i < len; i++)
    {
        int wid = 0;
        for(int j = 0; j < len; j++)
        {
            if(map[j][i] == '.')
            {
                wid++;
            }
            else
            {
                wid >= 2 ? cnt++ : false;
                wid = 0;
            }
        }
        if(wid >= 2)
        {
            cnt++;
        }
    }
    return cnt;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<std::string> map;
    int len;
    std::string s;
    
    std::cin >> len;
    for(int i = 0; i < len; i++)
    {
        std::cin >> s;
        map.push_back(s);
    }
    
    std::cout << x(map, len) << ' ' << y(map, len) << '\n';
    
    return 0;
}
