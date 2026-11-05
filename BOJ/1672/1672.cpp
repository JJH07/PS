//
//  main.cpp
//  1672
//
//  Created by 진준호 on 2020/02/24.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
std::map<std::string, std::string> memo;
void init_memo()
{
    memo["AA"] = "A";
    memo["AG"] = "C";
    memo["AC"] = "A";
    memo["AT"] = "G";
    memo["GA"] = "C";
    memo["GG"] = "G";
    memo["GC"] = "T";
    memo["GT"] = "A";
    memo["CA"] = "A";
    memo["CG"] = "T";
    memo["CC"] = "C";
    memo["CT"] = "G";
    memo["TA"] = "G";
    memo["TG"] = "A";
    memo["TC"] = "G";
    memo["TT"] = "T";
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int len;
    std::string dna, x, y;
    
    std::cin >> len >> dna;
    init_memo();
    y = dna[len - 1];
    for(int i = len - 2; i >= 0; i--)
    {
        x = dna[i];
        y = memo[x + y];
    }
    std::cout << y << '\n';
    return 0;
}
