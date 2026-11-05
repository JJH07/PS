#include <iostream>
#include <cstring>
#include <vector>

#define MAX 1001

int n, m, t, d[MAX];
bool check[MAX];
std::vector<int> tree[MAX];

bool dfs(int x)
{
	for(int i = 0; i < tree[x].size(); i++)
    {
		int t = tree[x][i];
		if(check[t])
        {
            continue;
        }
		check[t] = true;
        if(d[t] == 0 || dfs(d[t]))
        {
			d[t] = x;
			return true; 
		} 
	} 
	return false;
} 

int main(void)
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> t;
	while(t--)
    {
		int cnt = 0;
        std::cin >> n >> m;
		for(int i = 1; i <= m; i++)
        {
			int x, y;
            std::cin >> x >> y;
			for(int j = x; j <= y; j++)
            { 
				tree[i].push_back(j);
			}
		}
		for(int i = 1; i <= m; i++)
        {
            std::memset(check, 0, sizeof(check));
			if(dfs(i))
            {
				cnt++;
			}	
		}
        std::cout << cnt << '\n';
        std::memset(d, 0, sizeof(d));
        std::memset(check, 0, sizeof(check));
		for(int i = 1; i <= m; i++)
        {
			tree[i].clear();
		}
	}
	return 0;
} 