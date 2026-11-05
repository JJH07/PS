#include <iostream>
#include <vector>
#include <algorithm>
int n, m, table[9];
std::vector<int> list;
void pick(int picked, int idx)
{
    if(picked == m)
    {
        for(int i = 0; i < picked; i++)
        {
            std::cout << table[i] << ' ';
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
    std::sort(list.begin(), list.end());
    pick(0, 0);
    return 0;
}