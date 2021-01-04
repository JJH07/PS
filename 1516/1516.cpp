#include <iostream>
#include <vector>
#define MAX 501
int n, T[MAX], Constructed[MAX];
std::vector<int> Pre[MAX];
int Build(int idx)
{
    if(Constructed[idx] > 0)
    {
        return Constructed[idx];
    }
    int Time = 0;
    for(auto p : Pre[idx])
    {
        Time = std::max(Time, Build(p));
    }
    return Constructed[idx] = Time + T[idx];
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> T[i];
        while(1)
        {
            int C;
            std::cin >> C;
            if(C == -1)
            {
                break;
            }
            Pre[i].push_back(C);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        std::cout << Build(i) << '\n';
    }
    return 0;
}