//
//  main.cpp
//  1919
//
//  Created by 진준호 on 2020/01/07.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string a, b;
    int table[27], cnt = 0;
    
    for(int i = 0; i < 27; i++)
    {
        table[i] = 0;
    }
    std::cin >> a >> b;
    
    for(int i = 0; i < a.length(); i++)
    {
        table[a[i] - 'a']++;
    }
    for(int i = 0; i < b.length(); i++)
    {
        if(table[b[i] - 'a'] > 0)
        {
            table[b[i] - 'a']--;
        }
        else
        {
            cnt++;
        }
    }
    for(int i = 0; i <= 'z' - 'a'; i++)
    {
        cnt += table[i];
    }
    std::cout << cnt << '\n';
    return 0;
}
