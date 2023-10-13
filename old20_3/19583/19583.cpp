#include <iostream>
#include <cstring>
#include <set>

const int DAY = 1440;
int parse_time(const std::string &t)
{
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 5));
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s, e, q, s_Time, s_Name;
    std::set<std::string> book;
    int S, E, Q, ans = 0;

    std::cin >> s >> e >> q;
    S = parse_time(s);
    E = parse_time(e);
    Q = parse_time(q);
    while(!(std::cin >> s_Time).eof())
    {
        std::cin >> s_Name;
        int time = parse_time(s_Time);
        if(S >= time)
        {
            if(book.find(s_Name) == book.end())
            {
                book.insert(s_Name);
            }
        }
        else if(E <= time && time <= Q)
        {
            auto idx = book.find(s_Name);
            if(idx != book.end())
            {
                ans++;
                book.erase(idx);
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}