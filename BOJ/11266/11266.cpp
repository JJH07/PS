#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001

int V, E, discover[MAX], count;
bool cut[MAX];
std::vector<int> link[MAX];
int dfs(int now, bool root)
{
    discover[now] = ++count;
    int ret = count;
    int child = 0;
    for(int next : link[now])
    {
        if(!discover[next])
        {
            child++;
            int nret = dfs(next, 0);
            if(!root && discover[now] <= nret)
            {
                cut[now] = true;
            }
            ret = std::min(ret, nret);
        }
        else
        {
            ret = std::min(ret, discover[next]);
        }
    }
    if(root && child > 1)
    {
        cut[now] = true;
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int A, B;
        std::cin >> A >> B;
        link[A].push_back(B);
        link[B].push_back(A);
    }
    for(int i = 1; i <= V; i++)
    {
        if(!discover[i])
        {
            dfs(i, true);
        }
    }
    std::vector<int> ans;
    for(int i = 1; i <= V; i++)
    {
        if(cut[i])
        {
            ans.push_back(i);
        }
    }
    std::cout << ans.size() << '\n';
    for(auto x : ans)
    {
        std::cout << x << ' ';
    }
    return 0;
}