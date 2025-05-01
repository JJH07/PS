#include<bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> v;
    int n, k;
    std::cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            v.push_back(i);
        }
    }
    std::cout << (v.size() >= k ? v[k - 1] : 0) << '\n';
    return 0;
}