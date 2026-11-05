#include <iostream>
#include <set>
#include <cmath>
std::set<int> Prime[9];
bool is_Prime(int number)
{
    for(int i = 2; i <= (int)sqrt(number); i++)
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, ypow = 1;
    std::cin >> n;
    for(int i = 2; i < 10; i++)
    {
        if(is_Prime(i))
        {
            Prime[1].insert(i);
        }
    }
    for(int i = 2; i <= n; i++)
    {
        for(int front : Prime[i - 1])
        {
            for(int back = 0; back < 10; back++)
            {
                int next = front * 10 + back;
                if(is_Prime(next))
                {
                    Prime[i].insert(next);
                }
            }
        }
    }
    for(int ans : Prime[n])
    {
        std::cout << ans << '\n';
    }
    return 0;
}