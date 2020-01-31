//
//  main.cpp
//  12790
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T, hp, mp, atk, def, itemhp, itemmp, itematk, itemdef;
    std::cin >> T;
    while(T--)
    {
        std::cin >> hp >> mp >> atk >> def >> itemhp >> itemmp >> itematk >> itemdef;
        hp = hp + itemhp > 1 ? hp + itemhp : 1;
        mp = mp + itemmp > 1 ? mp + itemmp : 1;
        atk = atk + itematk > 0 ? atk + itematk : 0;
        def += itemdef;
        std::cout << hp + mp * 5 + (atk + def) * 2 << '\n';
    }
    
    return 0;
}
