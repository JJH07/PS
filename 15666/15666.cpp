#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
int n, m;
std::vector<int> list, table;
void pick(int picked, int idx)
{
    if(picked == m)
    {
        for(auto &x : table)
        {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }
    else
    {
        for(int i = idx; i < n; i++)
        {
            table[picked] = list[i];
            pick(picked + 1, i);
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
    list.erase(std::unique(list.begin(), list.end()), list.end());
    n = (int)list.size();
    pick(0, 0);
    return 0;
}