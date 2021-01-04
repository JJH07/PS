#include <iostream>
#include <vector>
#include <algorithm>
const int MAX = 1e9;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n, x, y;
        std::vector<int> list;
        std::cin >> n >> x >> y;
        int d = 1;
        for(int i = n - 1; i >= 1; i--)
        {
            if((y - x) % i == 0)
            {
                d = (y - x) / i;
                break;
            }
        }
        for(int i = x; i <= y; i += d)
        {
            list.push_back(i);
            n--;
        }
        x -= d;
        while(n > 0 && x > 0)
        {
            list.push_back(x);
            x -= d;
            n--;
        }
        y += d;
        while(n > 0 && y <= MAX)
        {
            list.push_back(y);
            y += d;
            n--;
        }
        std::sort(list.begin(), list.end());
        for(auto x : list)
        {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}