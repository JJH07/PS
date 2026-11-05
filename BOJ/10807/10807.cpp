#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, a;
    std::vector<int> v;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        std::cin >> t;
        v.push_back(t);
    }
    std::sort(v.begin(), v.end());
    std::cin >> a;

    std::cout << std::upper_bound(v.begin(), v.end(), a) - std::lower_bound(v.begin(), v.end(), a);
    return 0;
}
