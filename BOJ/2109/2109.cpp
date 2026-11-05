#include <bits/stdc++.h>
typedef std::pair<int, int> pii;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, ans = 0;
    std::vector<pii> v;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int p, d;
        std::cin >> p >> d;
        v.push_back({d, p});
    }
    std::sort(v.begin(), v.end());
    for(auto [Deadline, Pay] : v)
    {
        ans += Pay;
        pq.push(Pay);

        if(pq.size() > Deadline)
        {
            ans -= pq.top();
            pq.pop();
        }
    }
    std::cout << ans << '\n';
    return 0;
}