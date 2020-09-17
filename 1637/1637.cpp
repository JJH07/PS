#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 2147483647;
typedef long long ll;

int n;
ll A[20001], B[20001], C[20001];
ll func(ll height)
{
    ll ret = 0;
    for(int i = 0; i < n; i++)
    {
        if(height >= A[i])
        {
            ret += (std::min(height, C[i]) - A[i]) / B[i] + 1;
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> A[i] >> C[i] >> B[i];
    }
    ll l = 1, r = MAX;
    while(l <= r)
    {
        ll mid = (l + r) / 2;
        if(func(mid) % 2)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if(func(l) % 2)
    {
        std::cout << l << ' ' << func(l) - func(l - 1) << '\n';
    }
    else
    {
        std::cout << "NOTHING\n";
    }
    
    return 0;
}