#include <iostream>
#include <set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    std::set<int> unionSet;
    std::cin >> a >> b;
    for(int i = 0; i < a + b; i++)
    {
        int value;
        std::cin >> value;
        unionSet.insert(value);
    }
    const int unionSize = static_cast<int>(unionSet.size());
    std::cout << unionSize * 2 - a - b << '\n';
    return 0;
}
