//
//  main.cpp
//  5373
//
//  Created by 진준호 on 2020/03/30.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
std::string cube[6];
int table[6][4][3] = {{{0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {0, 1, 2}},
    {{8, 7, 6}, {2, 5, 8}, {8, 7, 6}, {6, 3, 0}},
    {{6, 3, 0}, {2, 5, 8}, {2, 5, 8}, {6, 3, 0}},
    {{2, 5, 8}, {2, 5, 8}, {6, 3, 0}, {6, 3, 0}},
    {{0, 1, 2}, {2, 5, 8}, {0, 1, 2}, {6, 3, 0}},
    {{8, 7, 6}, {8, 7, 6}, {8, 7, 6}, {8, 7, 6}}};
void init_cube()
{
    cube[0] = "wwwwwwwww"; //top[i]
    cube[5] = "yyyyyyyyy"; //down[i]
        
    cube[1] = "rrrrrrrrr"; //front[i]
    cube[4] = "ooooooooo"; //back[i]
        
    cube[2] = "ggggggggg"; //left[i]
    cube[3] = "bbbbbbbbb"; //right[i]
    
}
void process(std::string opt)
{
    int c_main, top, left, down, right;
    if(opt[0] == 'U')
    {
        c_main = 0;
        top = 4;
        down = 1;
        left = 2;
        right = 3;
    }
    else if(opt[0] == 'D')
    {
        c_main = 5;
        top = 4;
        down = 1;
        left = 3;
        right = 2;
    }
    else if(opt[0] == 'F')
    {
        c_main = 1;
        top = 0;
        down = 5;
        left = 2;
        right = 3;
    }
    else if(opt[0] == 'B')
    {
        c_main = 4;
        top = 0;
        down = 5;
        left = 3;
        right = 2;
    }
    else if(opt[0] == 'L')
    {
        c_main = 2;
        top = 0;
        down = 5;
        left = 4;
        right = 1;
    }
    else
    {
        c_main = 3;
        top = 0;
        down = 5;
        left = 1;
        right = 4;
    }
    std::string temp = ".........";
    if(opt[1] == '+')
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                int idx1 = i * 3 + j;
                int idx2 = j * 3 + (2 - i);
                temp[idx2] = cube[c_main][idx1];
            }
        }
        cube[c_main] = temp;
        for(int i = 0; i < 3; i++)
        {
            char &w_t = cube[top][table[c_main][0][i]];
            char &w_l = cube[left][table[c_main][1][i]];
            char &w_d = cube[down][table[c_main][2][i]];
            char &w_r = cube[right][table[c_main][3][i]];
            std::swap(w_t, w_l);
            std::swap(w_l, w_d);
            std::swap(w_d, w_r);
        }
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                int idx1 = i * 3 + j;
                int idx2 = (2 - j) * 3 + i;
                temp[idx2] = cube[c_main][idx1];
            }
        }
        cube[c_main] = temp;
        for(int i = 0; i < 3; i++)
        {
            char &w_t = cube[top][table[c_main][0][i]];
            char &w_l = cube[left][table[c_main][1][i]];
            char &w_d = cube[down][table[c_main][2][i]];
            char &w_r = cube[right][table[c_main][3][i]];
            std::swap(w_r, w_d);
            std::swap(w_d, w_l);
            std::swap(w_l, w_t);
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        init_cube();
        std::cin >> m;
        for(int j = 0; j < m; j++)
        {
            std::string opt;
            std::cin >> opt;
            process(opt);
        }
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                std::cout << cube[0][i * 3 + j];
            }
            std::cout << '\n';
        }
    }
    return 0;
}
