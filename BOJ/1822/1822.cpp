#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m), result;
    result.reserve(n);
    for(int &value : a)
    {
        std::cin >> value;
    }
    for(int &value : b)
    {
        std::cin >> value;
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int ai = 0, bi = 0;
    while(ai < n)
    {
        if(bi >= m || a[ai] < b[bi])
        {
            result.push_back(a[ai++]);
        }
        else if(a[ai] == b[bi])
        {
            ai++;
            bi++;
        }
        else
        {
            bi++;
        }
    }
    std::cout << result.size() << '\n';
    for(auto x : result)
    {
        std::cout << x << ' ';
    }
    return 0;
}
