//
//  main.cpp
//  1074
//
//  Created by 진준호 on 2019/12/27.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <cmath>

int N, r, c, counting = 0;
int dx[4] = {0, 0, 1, 1}, dy[4] = {0, 1, 0, 1};
bool z(int n, int sx, int sy)
{
    if(sx == r && sy == c)
    {
        return true;
    }
    bool ret = false;
    if(sx <= r && sy <= c && sx + n - 1 >= r && sy + n - 1 >= c)
    {
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] * n / 2 + sx;
            int ny = dy[i] * n / 2 + sy;
            if((ret = z(n / 2, nx, ny)))
            {
                return true;
            }
        }
    }
    else
    {
        counting += (n * n);
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> N >> r >> c;
    
    N = (int)std::pow(2, N);
    z(N, 0, 0);
    std::cout << counting << '\n';
    
    return 0;
}
