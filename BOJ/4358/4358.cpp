#include <iostream>
#include <map>
#include <string>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(4);
    int tot = 0;
    std::string str;
    std::map<std::string, int> table;
    while(std::getline(std::cin, str))
    {
        if(table.find(str) == table.end())
        {
            table.insert({str, 1});
        }
        else
        {
            table[str]++;
        }
        tot++;
    }
    for(auto species : table)
    {
        std::cout << species.first << ' ' << 100.0 * species.second / tot << '\n';
    }
    return 0;
}