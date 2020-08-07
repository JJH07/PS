#include <iostream>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, sum = 0, two = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tree;
        std::cin >> tree;
        sum += tree;
        two += tree / 2;
    }
    if(sum % 3 == 0 && two >= sum / 3)
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }
    
    return 0;
}