#include <iostream>
#include <vector>
#include <algorithm>

int n, list[3000];
int Go(int v)
{
    int ret = 0, chunk = 0;
    for(int i = 0; i < n; i++)
    {
        if(chunk + list[i] == v)
        {
            ret += chunk > 0 ? 1 : 0;
            chunk = 0;
        }
        else if(chunk + list[i] < v)
        {
            ret += chunk > 0 ? 1 : 0;
            chunk += list[i];
        }
        else
        {
            return -1;
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int Min = 100000, Max = -1, Sum = 0;
        std::vector<int> Cand;
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            std::cin >> list[i];
            Min = std::min(Min, list[i]);
            Max = std::max(Max, list[i]);
            Sum += list[i];
        }
        for(int i = n; i > 0; i--)
        {
            if(Sum % i > 0)
            {
                continue;
            }
            Cand.push_back(Sum / i);
        }
        int cnt = -1;
        for(auto x : Cand)
        {
            cnt = Go(x);
            if(cnt >= 0)
            {
                break;
            }
        }
        std::cout << cnt << '\n';
    }
    return 0;
}