#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

int n, m, ID[100001], indegree[100001], group[100001], ID_indexing;
bool finished[100001];
std::vector<int> link[100001];
std::vector<std::vector<int>> SCC;
std::stack<int> stk;

int dfs(int idx)
{
    ID[idx] = ++ID_indexing;
    stk.push(idx);

    int parent = ID[idx];
    for(auto next : link[idx])
    {
        if(ID[next] == 0)
        {
            parent = std::min(parent, dfs(next));
        }
        else if(!finished[next])
        {
            parent = std::min(parent, ID[next]);
        }
    }
    if(parent == ID[idx])
    {
        std::vector<int> C;
        int grp = SCC.size() + 1;
        while(!stk.empty())
        {
            int top = stk.top();
            stk.pop();
            C.push_back(top);
            finished[top] = true;
            group[top] = grp;
            if(top == idx)
            {
                break;
            }
        }
        SCC.push_back(C);
    }
    return parent;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n >> m;

        std::memset(ID, 0, sizeof(ID));
        std::memset(indegree, 0, sizeof(indegree));
        std::memset(finished, 0, sizeof(finished));
        for(int i = 0; i <= n; i++)
        {
            link[i].clear();
        }
        ID_indexing = 0;
        SCC.clear();

        for(int i = 0; i < m; i++)
        {
            int x, y;
            std::cin >> x >> y;
            link[x].push_back(y);
        }

        for(int i = 1; i <= n; i++)
        {
            if(ID[i] == 0)
            {
                dfs(i);
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(auto next : link[i])
            {
                if(group[i] != group[next])
                {
                    indegree[group[next]]++;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= SCC.size(); i++)
        {
            if(indegree[i] == 0)
            {
                ans++;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}