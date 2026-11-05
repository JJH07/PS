#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
int check(std::map<int, int> &t, int Max_cnt)
{
    std::vector<int> chk;
    for(auto x : t)
    {
        if(x.second == Max_cnt)
        {
            chk.push_back(x.first);
        }
    }
    return chk.size() > 1 ? chk[1] : chk[0];
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, sum = 0, Max_cnt = 0;
    std::vector<int> list;
    std::map<int, int> table;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        list.push_back(number);
        table[number]++;
        Max_cnt = std::max(Max_cnt, table[number]);
        sum += number;
    }
    std::sort(list.begin(), list.end());
    
    std::cout << round(sum / (double)n) << '\n' << list[n / 2] << '\n' << check(table, Max_cnt) << '\n' << list.back() - list.front();
    return 0;
}