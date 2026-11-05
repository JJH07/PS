#include <bits/stdc++.h>
typedef std::pair<int, int> pii;

int n, L, P;
std::vector<pii> gas;
std::priority_queue<int> pq;

int solve()
{
    int e = 0, ret = 0;
    for(; e < n; e++)
    {
        if(gas[e].first > P)
        {
            break;
        }
        pq.push(gas[e].second);
    }
    while(!pq.empty())
    {
        if(L <= P)
        {
            break;
        }
        P += pq.top();
        pq.pop();
        ++ret;

        for(; e < n; e++)
        {
            if(gas[e].first > P)
            {
                break;
            }
            pq.push(gas[e].second);
        }
    }
    return L <= P ? ret : -1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        gas.push_back({a, b});
    }
    std::sort(gas.begin(), gas.end());
    std::cin >> L >> P;

    std::cout << solve() << '\n';
    return 0;
}