#include <iostream>
#include <queue>
#include <vector>
typedef std::pair<int, int> pii;
int n, m;
int simulate()
{
    std::priority_queue<int> pq;
    std::queue<pii> q;

    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int p;
        std::cin >> p;
        pq.push(p);
        q.push({p, i});
    }
    int printed = 0;
    while(!q.empty())
    {
        auto [p, idx] = q.front();
        q.pop();
        if(p != pq.top())
        {
            q.push({p, idx});
            continue;
        }
        printed++;
        pq.pop();
        if(idx == m)
        {
            break;
        }
    }
    return printed;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int tc;
    std::cin >> tc;
    while(tc--)
    {
        std::cout << simulate() << '\n';
    }

    return 0;
}