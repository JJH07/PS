#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

std::stack<int> stk;
int V, E, ID[10001], ID_indexing;
bool finished[10001];
std::vector<int> conn[10001];
std::vector<std::vector<int>> ans;
int dfs(int idx)
{
    ID[idx] = ++ID_indexing;
    stk.push(idx);

    int parent = ID[idx];
    for(auto next : conn[idx])
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
        std::vector<int> SCC;
        while(!stk.empty())
        {
            int top = stk.top();
            stk.pop();
            finished[top] = true;
            SCC.push_back(top);
            if(idx == top)
            {
                break;
            }
        }
        std::sort(SCC.begin(), SCC.end());
        ans.push_back(SCC);
    }

    return parent;
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
        if(A == B)
        {
            continue;
        }
        conn[A].push_back(B);
    }
    for(int i = 1; i <= V; i++)
    {
        if(ID[i] == 0)
        {
            dfs(i);
        }
    }
    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << '\n';
    for(auto x : ans)
    {
        for(auto y : x)
        {
            std::cout << y << ' ';
        }
        std::cout << "-1\n";
    }
    return 0;
}