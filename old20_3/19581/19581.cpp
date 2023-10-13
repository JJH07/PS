#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <bitset>
#define MAX 100001

int n;
std::bitset<MAX> visited;
std::vector<std::pair<int, int>> link[MAX];
int node, dist;
void dfs(int from, int except, int price)
{
	if(from == except)
	{
		return ;
	}
	visited.set(from, true);
	if(dist < price)
	{
		dist = price;
		node = from;
	}
	for(auto [next, w] : link[from])
	{
		if(!visited[next])
		{
			dfs(next, except, price + w);
		}
	}
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

	std::cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int a, b, w;
		std::cin >> a >> b >> w;
		link[a].push_back({b, w});
		link[b].push_back({a, w});
	}
	int ans = -1, A, B;
	dfs(1, -1, 0);
	visited.reset();
	A = node;
	dist = 0;

	dfs(A, -1, 0);
	visited.reset();
	B = node;
	dist = 0;

	dfs(A, B, 0);
	visited.reset();
	ans = std::max(ans, dist);
	dist = 0;

	dfs(B, A, 0);
	visited.reset();
	ans = std::max(ans, dist);
	
	std::cout << ans << '\n';
	return 0;
}