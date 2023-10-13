#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
int n, m;
std::vector<int> list, table;
std::set<std::vector<int>> visited;
void pick(int picked, int used)
{
    if(picked == m)
    {
        if(visited.find(table) != visited.end())
        {
            return ;
        }
        visited.insert(table);
        for(int i = 0; i < picked; i++)
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
    table.resize(m);
    std::sort(list.begin(), list.end());
    pick(0, 0);
    return 0;
}