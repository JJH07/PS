#include <iostream>
#include <string>
#include <vector>
std::vector<int> make_table(std::string pattern)
{
    int p_sz = (int)pattern.size();
    std::vector<int> table(p_sz, 0);
    int j = 0;
    for(int i = 1; i < p_sz; i++)
    {
        while(j > 0 && pattern[i] != pattern[j])
        {
            j = table[j - 1];
        }
        if(pattern[i] == pattern[j])
        {
            table[i] = ++j;
        }
    }
    return table;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string str;
    std::vector<int> table;

    while(1)
    {
        std::cin >> str;
        if(str.size() == 1 && str[0] == '.')
        {
            break;
        }
        table = make_table(str);
        int ans = 1;
        if(str.size() % (str.size() - table.back()) == 0)
        {
            ans = str.size() / (str.size() - table.back());
        }
        std::cout << ans << '\n';
    }
    return 0;
}