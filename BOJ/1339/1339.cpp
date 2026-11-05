//
//  main.cpp
//  1339
//
//  Created by 진준호 on 2020/01/14.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::string> list;
std::vector<char> w_list;
int n, max_v, exist[30];

bool comp(const std::string &a, const std::string &b)
{
    return a.length() > b.length();
}
void permutation(int number, int cnt)
{
    int sum = 0;
    if(cnt == w_list.size())
    {
        for(std::vector<std::string>::iterator it = list.begin(); it !=  list.end(); it++)
        {
            int rp = 1;
            for(std::string::reverse_iterator rit = it->rbegin(); rit != it->rend(); rit++)
            {
                sum += (exist[*rit - 'A'] * rp);
                rp *= 10;
            }
        }
        max_v = std::max(max_v, sum);
    }
    else
    {
        int check = 0;
        for(std::vector<char>::iterator it = w_list.begin(); it != w_list.end(); it++)
        {
            if(exist[*it - 'A'] == -1)
            {
                check++;
                exist[*it - 'A'] = number;
                permutation(number - 1, cnt + 1);
                exist[*it - 'A'] = -1;
            }
        }
        if(check == 0 && cnt < w_list.size())
        {
            permutation(number, cnt + 1);
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::fill(exist, exist + 30, -1);
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        list.push_back(tmp);
    }
    for(std::vector<std::string>::iterator it = list.begin(); it != list.end(); it++)
    {
        for(std::string::iterator sit = it->begin(); sit != it->end(); sit++)
        {
            if(exist[*sit - 'A'] == -1)
            {
                exist[*sit - 'A'] = 1;
                w_list.push_back(*sit);
            }
        }
    }
    
    std::fill(exist, exist + 30, -1);
    
    permutation(9, 0);
    
    std::cout << max_v << '\n';
    return 0;
}
