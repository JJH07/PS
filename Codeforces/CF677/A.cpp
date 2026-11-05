#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
int table[10001];
void init()
{
    table[10000] = 5;
    for(int i = 1; i <= 9; i++)
    {
        table[i] = 1;
    }
    for(int i = 10; i <= 99; i++)
    {
        table[i] = 2;
    }
    for(int i = 100; i <= 999; i++)
    {
        table[i] = 3;
    }
    for(int i = 1000; i <= 9999; i++)
    {
        table[i] = 4;
    }
}
int go(int x)
{
    int ret = 0;
    for(int i = 1; i <= 10000; i++)
    {
        int number = i;
        int jump = (int)pow(10, table[i]);
        while(number <= 10000)
        {
            ret += table[number];
            if(number == x)
            {
                return ret;
            }
            number = number * jump + i;
        }
    }
    return -1;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    init();
    int t;
    std::cin >> t;
    while(t--)
    {
        int x, ans = 0;
        std::cin >> x;
        std::cout << go(x) << '\n';
    }
    return 0;
}