#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 100001

int n, left[MAX], right[MAX];
bool visited[MAX];
std::vector<int> link[MAX];
int cnt = 1;
void dfs(int idx)
{
    left[idx] = cnt++;
    for(int next : link[idx])
    {
        if(!visited[next])
        {
            visited[next] = true;
            dfs(next);
        }
    }
    right[idx] = cnt++;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int s, e;
        std::cin >> s;
        while(1)
        {
            std::cin >> e;
            if(e == -1)
            {
                break;
            }
            link[s].push_back(e);
            link[e].push_back(s);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        std::sort(link[i].begin(), link[i].end());
    }
    int root;
    std::cin >> root;
    visited[root] = true;
    dfs(root);
    for(int i = 1; i <= n; i++)
    {
        std::cout << i << ' ' << left[i] << ' ' <<  right[i] << '\n';
    }
    return 0;
}