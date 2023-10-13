#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 100001

int t, n;
std::deque<int> list;
void parse(std::string p)
{
    if(n == 0)
    {
        return ;
    }
    int len = (int)p.length(), number = 0;
    for(int i = 1; i < len; i++)
    {
        if(p[i] >= '0' && p[i] <= '9')
        {
            number = number * 10 + (p[i] - '0');
        }
        else
        {
            list.push_back(number);
            number = 0;
        }
    }
}
bool go(std::string p)
{
    int reverse = 0;
    for(char op : p)
    {
        if(op == 'R')
        {
            reverse = (reverse + 1) % 2;
        }
        else if(list.size() == 0)
        {
            return false;
        }
        else
        {
            reverse ? list.pop_back() : list.pop_front();
        }
    }
    if(reverse)
    {
        std::reverse(list.begin(), list.end());
    }
    return true;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> t;
    while(t--)
    {
        std::string p, l;
        std::cin >> p >> n >> l;
        parse(l);
        if(go(p))
        {
            int sz = (int)list.size();
            std::cout << '[';
            for(int i = 0; i < sz; i++)
            {
                std::cout << list[i];
                if(i < sz - 1)
                {
                    std::cout << ',';
                }
            }
            std::cout << "]\n";
        }
        else
        {
            std::cout << "error\n";
        }
        list.clear();
    }
    return 0;
}