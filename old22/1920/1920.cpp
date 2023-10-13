#include <bits/stdc++.h>
typedef long long ll;

int n, m;
std::vector<ll> list;

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll num;
        std::cin >> num;
        list.push_back(num);
    }
    std::sort(list.begin(), list.end());

    std::cin >> m;
    while(m--)
    {
        ll key;
        int s = 0, e = n - 1;

        std::cin >> key;
        while(s <= e)
        {
            int mid = (s + e) >> 1;
            if(list[mid] <= key)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        std::cout << (list[e] == key) << '\n';
    }
    return 0;
}