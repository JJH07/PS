#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

int n, m, ID[100000], indegree[100001], group[100001], ID_indexing;
std::vector<int> link[100000];
bool finished[100000];
std::vector<std::vector<int>> SCC;
std::stack<int> stk;
std::queue<int> q;

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
            finished[top] = true;
            C.push_back(top);
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
        std::memset(group, 0, sizeof(group));
        for(int i = 0; i < 100000; i++)
        {
            link[i].clear();
        }
        std::memset(finished, 0, sizeof(finished));
        SCC.clear();
        while(!q.empty())
        {
            q.pop();
        }

        for(int i = 0; i < m; i++)
        {
            int A, B;
            std::cin >> A >> B;
            link[A].push_back(B);
        }

        for(int i = 0; i < n; i++)
        {
            if(ID[i] == 0)
            {
                dfs(i);
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(auto next : link[i])
            {
                if(group[i] != group[next])
                {
                    indegree[group[next]]++;
                }
            }
        }

        int ans = -1;
        for(int i = 1; i <= (int)SCC.size(); i++)
        {
            if(indegree[i] == 0)
            {
                ans = i;
                q.push(i);
            }
        }
        if(q.size() == 1)
        {
            while(!q.empty())
            {
                int front = q.front();
                q.pop();
                for(auto now : SCC[front - 1])
                {
                    for(auto next : link[now])
                    {
                        if(group[now] != group[next])
                        {
                            indegree[group[next]]--;
                            if(indegree[group[next]] == 0)
                            {
                                q.push(group[next]);
                            }
                        }
                    }
                }
            }
            for(int i = 1; i <= (int)SCC.size(); i++)
            {
                if(indegree[i] > 0)
                {
                    ans = -1;
                }
            }
            if(ans == -1)
            {
                std::cout << "Confused\n";
            }
            else
            {
                std::sort(SCC[ans - 1].begin(), SCC[ans - 1].end());
                for(auto x : SCC[ans - 1])
                {
                    std::cout << x << '\n';
                }
            }
        }
        else
        {
            std::cout << "Confused\n";
        }
        std::cout << '\n';
    }

    return 0;
}