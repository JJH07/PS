#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
typedef long long ll;

int n;
std::vector<ll> list;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll number;
        std::cin >> number;
        list.push_back(number);
    }
    std::sort(list.begin(), list.end());

    auto l = list.begin(), r = list.end() - 1;
    ll x = *l, y = *r, sum = *l + *r;
    while(l < r)
    {
        ll temp = *l + *r;
        if(abs(sum) > abs(temp))
        {
            sum = temp;
            x = *l;
            y = *r;
        }
        if(temp <= 0)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    std::cout << x << ' ' << y << '\n';
    return 0;
}