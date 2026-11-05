#include <iostream>
#include <string>
#include <algorithm>
#include <set>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::set<std::string> log;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::string name, status;
        std::cin >> name >> status;
        if(status == "enter")
        {
            log.insert(name);
        }
        else
        {
            log.erase(log.find(name));
        }
    }
    for(auto it = log.rbegin(); it != log.rend(); it++)
    {
        std::cout << *it << '\n';
    }
    return 0;
}