#include <iostream>
#include <cstring>
#define MAX 1001
int grundy[MAX];
bool table[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    grundy[2] = 1;

    int n;
    std::cin >> n;
    for(int N = 3; N <= n; N++)
    {
        std::memset(table, 0, sizeof(table));
        for(int i = 0; i < (N - 2) / 2; i++)
        {
            int g = grundy[i] ^ grundy[N - 2 - i];
            table[g] = true;
        }
        for(int i = 0; i < MAX; i++)
        {
            if(!table[i])
            {
                grundy[N] = i;
                break;
            }
        }
    }
    std::cout << (grundy[n] ? 1 : 2) << '\n';
    return 0;
}