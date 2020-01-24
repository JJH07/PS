//
//  main.cpp
//  2153
//
//  Created by 진준호 on 2020/01/21.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
bool is_prime(int number)
{
    for(int i = 2; i <= (int)sqrt(number); i++)
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string word;
    int sum = 0;
    
    std::cin >> word;
    
    for(std::string::iterator it = word.begin(); it != word.end(); it++)
    {
        if(*it > 'Z')
        {
            sum += (*it - 'a' + 1);
        }
        else
        {
            sum += (*it - 'A' + 1);
        }
    }
    
    if(is_prime(sum))
    {
        std::cout << "It is a prime word.\n";
    }
    else
    {
        std::cout << "It is not a prime word.\n";
    }
    
   
    return 0;
}
