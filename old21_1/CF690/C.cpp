#include <iostream>
#include <cstring>
bool table[10];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {   
        std::memset(table, 0, sizeof(table));
        int x;
        std::cin >> x;
        for(int i = 9; i > 0; i--)
        {
            if(x >= i)
            {
                x -= i;
                table[i] = 1;
            }
            if(x == 0)
            {
                break;
            }
        }
        if(x != 0)
        {
            std::cout << "-1\n";
        }
        else
        {
            for(int i = 1; i < 10; i++)
            {
                if(table[i])
                {
                    std::cout << i;
                }
            }
            std::cout << '\n';   
        }
    }
    return 0;
}