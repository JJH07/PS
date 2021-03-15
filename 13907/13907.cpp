#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1001
#define INF 2e9
typedef long long ll;
typedef std::pair<int, int> pii;
int n, m, k, s, d, distance[MAX][MAX];
std::vector<pii> link[MAX];
std::vector<ll> list;
void dijkstra()
{
    std::priority_queue<std::pair<int, pii>> pq;

	pq.push({0, {s, 0}});
	distance[s][0] = 0;
	while(!pq.empty())
	{
        auto top = pq.top();
		pq.pop();
        int dist = -top.first;
        auto [now, cnt] = top.second;
		if (cnt == n)
        {
            continue;
        }
		if (distance[now][cnt] < dist)
        {
            continue;
        }
		for (auto [next, v] : link[now])
		{
            int ndist = distance[now][cnt] + v;
			if (distance[next][cnt + 1] > ndist)
			{
				distance[next][cnt + 1] = ndist;
				pq.push({-ndist, {next, cnt + 1}});
			}
		}
	}
}

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(distance[0], distance[0] + MAX * MAX, INF);

	std::cin >> n >> m >> k >> s >> d;

	for (int i = 0; i < m; i++)
	{
        int a, b, c;
        std::cin >> a>> b >> c;
		link[a].push_back({b, c});
		link[b].push_back({a, c});
	}
    list.push_back(0);
    for(int i = 0; i < k; i++)
    {
        ll t;
        std::cin >> t;
        list.push_back(t);
    }
    dijkstra();
	for(auto tax : list)
	{
		int ans = INF;
		for (int i = 1; i < n; i++)
		{
			distance[d][i] += (i * tax);
			ans = std::min(ans, distance[d][i]);
		}
		std::cout << ans << '\n';
	}

	return 0;
}