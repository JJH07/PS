#include <iostream>
#include <map>
#include <set>
#include <string>
std::set<std::string> list;
std::map<std::string, int> counting;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n, ans = 0;
        std::cin >> n;
        while(n--)
        {
            std::string gear, type;
            std::cin >> gear >> type;
            if(list.find(gear) == list.end())
            {
                list.insert(gear);
                counting.find(type) == counting.end() ? counting[type] = 1 : counting[type]++;
            }
        }
        for(auto [name, cnt] : counting)
        {
            ans = ans + ans * cnt + cnt;
        }
        list.clear();
        counting.clear();
        std::cout << ans << '\n';
    }
    return 0;
}