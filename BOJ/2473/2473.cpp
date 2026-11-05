#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 5000
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

    ll L, M, R, Sum = (ll)1e12;
    for(int l = 0; l < n - 2; l++)
    {
        int m = l + 1, r = n - 1;
        while(m < r)
        {
            ll temp = list[l] + list[m] + list[r];
            if(std::abs(Sum) > std::abs(temp))
            {
                Sum = temp;
                L = list[l];
                M = list[m];
                R = list[r];
            }
            if(temp < 0)
            {
                m++;
            }
            else
            {
                r--;
            }
        }
    }
    std::cout << L << ' ' << M << ' ' << R << '\n';
    return 0;
}