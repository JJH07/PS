#include <iostream>
#include <algorithm>

const int MAX = 2147483647;
typedef long long ll;

int n;
ll start[20001], step[20001], end[20001];
ll countUpTo(ll value)
{
    ll count = 0;
    for(int i = 0; i < n; i++)
    {
        if(value >= start[i])
        {
            count += (std::min(value, end[i]) - start[i]) / step[i] + 1;
        }
    }
    return count;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> start[i] >> end[i] >> step[i];
    }
    ll left = 1, right = MAX;
    while(left <= right)
    {
        ll mid = (left + right) / 2;
        if(countUpTo(mid) % 2)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    const ll count = countUpTo(left);
    if(count % 2)
    {
        std::cout << left << ' ' << count - countUpTo(left - 1) << '\n';
    }
    else
    {
        std::cout << "NOTHING\n";
    }

    return 0;
}
