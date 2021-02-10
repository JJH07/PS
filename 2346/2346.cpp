#include <iostream>
#include <queue>
typedef std::pair<int, int> pii;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::deque<pii> q;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int m;
        std::cin >> m;
        if(m > 0)
        {
            m--;
        }
        q.push_back({m, i});
    }
    int idx = 0, sz = (int)q.size();
    while(sz > 0)
    {
        if(idx < 0 || idx >= sz)
        {
            idx = (sz + (idx % sz)) % sz;
        }
        pii now = q[idx];
        std::cout << now.second << ' ';
        q.erase((q.begin() + idx));
        idx += now.first;
        sz--;
    }
    return 0;
}