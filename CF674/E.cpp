#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
typedef std::vector<int> Person;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, Max, Min = 0;
    Person Alice(3), Bob(3);
    std::cin >> n;
    for(int i = 0; i < 3; i++)
    {
        std::cin >> Alice[i];
    }
    for(int i = 0; i < 3; i++)
    {
        std::cin >> Bob[i];
    }
    Min = std::max(Min, Alice[0] - Bob[0] - Bob[2]);
    Min = std::max(Min, Alice[1] - Bob[1] - Bob[0]);
    Min = std::max(Min, Alice[2] - Bob[2] - Bob[1]);
    Max += std::min(Alice[0], Bob[1]);
    Max += std::min(Alice[1], Bob[2]);
    Max += std::min(Alice[2], Bob[0]);
    std::cout << Min << ' ' << Max << '\n';
    return 0;
}