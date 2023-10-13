#include <iostream>

int n, m;
int table[9];
void pick(int picked, int number)
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
        for(int i = number; i <= n; i++)
        {
            table[picked] = i;
            pick(picked + 1, i);
        }  
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    pick(0, 1);
    return 0;
}