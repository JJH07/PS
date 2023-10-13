#include <iostream>
#include <string>
#include <vector>
int max_v = 0;
void make_table(std::string pattern)
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
            max_v = std::max(max_v, table[i]);
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string str;
    std::cin >> str;

    for(int i = 0; i < (int)str.size(); i++)
    {
        make_table(str.substr(i, str.size()));
    }
    std::cout << max_v << '\n';
    
    return 0;
}