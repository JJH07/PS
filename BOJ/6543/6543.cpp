#include <bits/stdc++.h>
#define MAX 5001
typedef std::pair<int, int> pii;

std::vector<int> V[MAX];
std::vector<std::vector<int>> SCC;
int ID[MAX], finished[MAX], idx, gidx, answer[MAX];
std::stack<int> stk;

int Make_SCC(int now)
{
    ID[now] = ++idx;
    stk.push(now);

    int parent = ID[now];
    for(int next : V[now])
    {
        if(ID[next] == 0)
        {
            parent = std::min(parent, Make_SCC(next));
        }
        else if(finished[next] == 0)
        {
            parent = std::min(parent, ID[next]);
        }
    }
    if(parent == ID[now])
    {
        ++gidx;
        std::vector<int> scc;
        while(!stk.empty())
        {
            int top = stk.top();
            stk.pop();
            finished[top] = gidx;
            scc.push_back(top);
            if(now == top)
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    while(1)
    {
        std::cin >> n;
        if(n == 0)
        {
            break;
        }

        for(int i = 0; i < MAX; i++)
        {
            V[i].clear();
        }
        while(!stk.empty())
        {
            stk.pop();
        }
        idx = gidx = 0;
        std::memset(ID, 0, sizeof(ID));
        std::memset(finished, 0, sizeof(finished));
        std::memset(answer, -1, sizeof(answer));
        std::cin >> m;
        for(int i = 0; i < m; i++)
        {
            int v, w;
            std::cin >> v >> w;
            V[v].push_back(w);
        }
        for(int i = 1; i <= n; i++)
        {
            if(ID[i] == 0)
            {
                Make_SCC(i);
            }
        }
        for(auto scc : SCC)
        {
            int FLAG = 1;
            for(auto it = scc.begin(); it != scc.end() && FLAG; it++)
            {
                for(int next : V[*it])
                {
                    if(finished[*it] != finished[next])
                    {
                        FLAG = 0;
                    }
                }
            }
            for(int node : scc)
            {
                answer[node] = FLAG;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(answer[i])
            {
                std::cout << i << ' ';
            }
        }
        std::cout << '\n';
    }
    return 0;
}