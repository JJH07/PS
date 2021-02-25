#include <iostream>
#include <string>
#include <vector>
typedef std::pair<int, int> pii;
std::vector<pii> list;
void parse(std::string s)
{
    s += '+';
    int offset = 1, number = 0;
    for(auto c : s)
    {
        if('0' <= c && c <= '9')
        {
            number = number * 10 + c - '0';
        }
        else if(list.empty())
        {
            list.push_back({offset, number});
            offset = c == '+' ? 1 : -1;
            number = 0;
        }
        else
        {
            auto e_it = list.end() - 1;
            if(e_it->first < 0)
            {
                e_it->second += number;
            }
            else
            {
                list.push_back({offset, number});
            }
            offset = c == '+' ? 1 : -1;
            number = 0;
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int ans = 0;
    std::string s;
    std::cin >> s;
    parse(s);
    for(auto x : list)
    {
        ans += x.first * x.second;
    }
    std::cout << ans << '\n';
    return 0;
}