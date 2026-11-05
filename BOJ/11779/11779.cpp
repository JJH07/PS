#include <iostream>
#include <vector>
#include <queue>

const int INF = 100000001;
struct ticket{
    int city, price;
    bool operator<(const ticket &rhs) const{
        return price > rhs.price;
    }
};
std::vector<int> dist, trace;
std::vector<ticket> bus[1001];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, s, e;
    std::priority_queue<ticket> pq;
    std::cin >> n >> m;
    dist.resize(n + 1, INF);
    trace.resize(n + 1, -1);
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        bus[a].push_back({b, c});
    }
    std::cin >> s >> e;

    pq.push({s, 0});
    dist[s] = 0;
    while(!pq.empty())
    {
        auto [node, tprice] = pq.top();
        pq.pop();
        if(dist[node] < tprice)
        {
            continue;
        }
        if(node == e)
        {
            break;
        }
        for(auto [next, price] : bus[node])
        {
            int nprice = dist[node] + price;
            if(dist[next] > nprice)
            {
                dist[next] = nprice;
                pq.push({next, nprice});
                trace[next] = node;
            }
        }
    }
    int tracing = e;
    std::vector<int> ans;
    while(tracing > 0)
    {
        ans.push_back(tracing);
        tracing = trace[tracing];
    }
    std::cout << dist[e] << '\n' << ans.size() << '\n';
    for(auto x = ans.rbegin(); x != ans.rend(); x++)
    {
        std::cout << *x << ' ';
    }
    return 0;
}