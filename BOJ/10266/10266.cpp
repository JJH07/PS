#include <iostream>
#include <vector>
#include <string>
std::vector<int> make_table(std::vector<int> pattern)
{
    int pattern_sz = (int)pattern.size();
    std::vector<int> ret(pattern_sz, 0);
    for(int i = 1, j = 0; i < pattern_sz; i++)
    {
        while(j > 0 && pattern[i] != pattern[j])
        {
            j = ret[j - 1];
        }
        if(pattern[i] == pattern[j])
        {
            ret[i] = ++j;
        }
    }
    return ret;
}
bool KMP(std::vector<int> parent, std::vector<int> pattern)
{
    std::vector<int> fail_table = make_table(pattern);
    int main_sz = (int)parent.size();
    for(int i = 0, j = 0; i < main_sz; i++)
    {
        while(j > 0 && parent[i] != pattern[j])
        {
            j = fail_table[j - 1];
        }
        if(parent[i] == pattern[j])
        {
            if(j == pattern.size() - 1)
            {
                return true;
            }
            else
            {
                j++;
            }
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::vector<int> clock[2], pattern[2];
    std::cin >> n;
    
    for(int i = 0; i < 2; i++)
    {
        clock[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            std::cin >> clock[i][j];
        }
        std::sort(clock[i].begin(), clock[i].end());
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j == 0)
            {
                pattern[i].push_back(360000 - clock[i][n - 1] + clock[i][j]);
            }
            else
            {
                pattern[i].push_back(clock[i][j] - clock[i][j - 1]);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        pattern[1].push_back(pattern[1][i]);
    }
    if(!KMP(pattern[1], pattern[0]))
    {
        std::cout << "im";
    }
    std::cout << "possible\n";
    return 0;
}