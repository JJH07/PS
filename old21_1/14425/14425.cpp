#include <iostream>
#include <string>
#include <set>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::set<std::string> list;
    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        std::string str;
        std::cin >> str;
        list.insert(str);
    }
    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        std::string str;
        std::cin >> str;
        if(list.find(str) != list.end())
        {
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}