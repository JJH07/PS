#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#define MAX 10001

int n, m, s, t, ID[MAX], ID_idx, group[MAX];
bool finish[MAX];
std::vector<int> link[MAX];
std::vector<std::vector<int>> SCC;
std::stack<int> stk;

int Make_SCC(int idx)
{
    ID[idx] = ++ID_idx;
    stk.push(idx);

    int parent = ID[idx];
    for(int next : link[idx])
    {
        if(ID[next] == 0)
        {
            parent = std::min(parent, Make_SCC(next));
        }
        else if(!finish[next])
        {
            parent = std::min(parent, ID[next]);
        }
    }
    if(parent == ID[idx])
    {
        std::vector<int> scc;
        int grp = SCC.size();
        while(!stk.empty())
        {
            int top = stk.top();
            stk.pop();
            finish[top] = true;
            scc.push_back(top);
            group[top] = grp;
            if(top == idx)
            {
                break;
            }
        }
        SCC.push_back(scc);
    }
    return parent;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        link[a].push_back(b);
    }
    for(int i = 1; i <= n; i++)
    {
        if(ID[i] == 0)
        {
            Make_SCC(i);
        }
    }
    
    s = group[s];
    t = group[t];
    int ans = (int)SCC[s].size();
    if(s != t)
    {
        int dist[MAX];
        std::memset(dist, 0, sizeof(dist));
        std::queue<std::pair<int, int>> q;
        
        q.push({s, ans});
        dist[s] = ans;
        while(!q.empty())
        {
            auto [now, d] = q.front();
            q.pop();
            if(now == t)
            {
                continue;
            }
            for(auto node : SCC[now])
            {
                for(int next : link[node])
                {
                    if(group[node] == group[next])
                    {
                        continue;
                    }
                    int ndist = dist[now] + SCC[group[next]].size();
                    if(dist[group[next]] < ndist)
                    {
                        dist[group[next]] = ndist;
                        q.push({group[next], ndist});
                    }
                }
            }
        }
        ans = dist[t];
    }
    std::cout << ans << '\n';
    return 0;
}