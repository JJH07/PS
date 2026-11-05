//
//  main.cpp
//  2306
//
//  Created by 진준호 on 2020/02/10.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>

std::string DNA;
int memo[501][501];
int go(int l, int r)
{
    if(l >= r)
    {
        return l == r ? 1 : 0;
    }
    int &ret = memo[l][r];
    if(ret != -1)
    {
        return ret;
    }
    if((DNA[l] == 'a' && DNA[r]  == 't') || (DNA[l] == 'g' && DNA[r] == 'c'))
    {
        ret = go(l + 1, r - 1);
    }
    else
    {
        ret = 1 + std::min(go(l + 1 , r), go(l, r - 1));
    }
    for(int i = l; i <= r; i++)
    {
        if(DNA[i] == 'a' || DNA[i] == 'g')
        {
            ret = std::min(ret, go(l, i - 1) + go(i, r));
        }
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::fill(memo[0], memo[0] +  501 * 501, -1);
    
    std::cin >> DNA;
    
    std::cout << (int)DNA.length() -  go(0, (int)DNA.length() - 1) << '\n';
    
    return 0;
}
