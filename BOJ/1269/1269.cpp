#include <iostream>
#include <set>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b;
    std::set<int> s;
    std::cin >> a >> b;
    for(int i = 0; i < a + b; i++)
    {
        int n;
        std::cin >> n;
        s.insert(n);
    }
    int sz = (int)s.size();
    std::cout << sz * 2 - a - b << '\n';
    return 0;
}