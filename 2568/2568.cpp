#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
typedef std::pair<int, int> pii;
int n, step[MAX];
bool check[MAX];
std::vector<pii> line;
std::vector<int> ans;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);    

	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a, b;
		std::cin >> a >> b;
		line.push_back({a, b});
	}
	std::sort(line.begin(), line.end());
	for(int i = 0; i < n; i++)
	{
		if(ans.empty() || ans.back() < line[i].second)
		{
			ans.push_back(line[i].second);
			step[i] = ans.size() - 1;
		}
		else
		{
			auto idx = std::lower_bound(ans.begin(), ans.end(), line[i].second);
			*idx = line[i].second;
			step[i] = idx - ans.begin();
		}
	}
	int cnt = (int)ans.size() - 1;
	std::cout << n - ans.size() << '\n';
	for(int i = n - 1; i >= 0; i--)
	{
		if(step[i] == cnt)
		{
			check[i] = true;
			cnt--;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(!check[i])
		{
			std::cout << line[i].first << '\n';
		}
	}
	return 0;
}