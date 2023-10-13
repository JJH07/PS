#include <iostream>
#include <vector>
#include <algorithm>

int n, m, table[9];
std::vector<int> list;
void pick(int picked, int used)
{
    if(picked == m)
    {
        for(int i = 0; i < m; i++)
        {
            std::cout << table[i] << ' ';
        }
        std::cout << '\n';
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(!(used & (1 << i)))
            {
                table[picked] = list[i];
                pick(picked + 1, used + (1 << i));   
            }
        }   
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        list.push_back(number);
    }
    std::sort(list.begin(), list.end());
    pick(0, 0);
    return 0;  
}