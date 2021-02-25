#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
ll count(ll number)
{
    number++;
    ll ret = 0, pos = 1, check = number;
    while(number)
    {
        if(check & pos)
        {
            ret += (check % pos) + (check - check % (pos * 2)) / 2;
        }
        else
        {
            ret += (check - check % pos) / 2;
        }
        pos *= 2;
        number /= 2;
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    ll a, b;
    std::cin >> a >> b;
    std::cout << count(b) - count(a - 1) << '\n';
    return 0;
}