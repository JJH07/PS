#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <set>

int n, m, ID[41], ID_cnt, group[41], indegree[41];
bool finished[41];
std::set<int> link[41];
std::vector<std::vector<int>> SCC;
std::stack<int> stk;

int dfs(int idx)
{
    ID[idx] = ++ID_cnt;
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
        std::vector<int> scc;
        int gidx = SCC.size();
        while(!stk.empty())
        {
            int top = stk.top();
            stk.pop();
            finished[top] = 1;
            group[top] = gidx;
            scc.push_back(top);
            if(top == idx)
            {
                break;
            }
        }
        SCC.push_back(scc);
    }
    return parent;
}
void make_link(int xi, int xj)
{
    if(xi < 0)
    {
        xi = -xi + n;
    }
    if(xj < 0)
    {
        xj = -xj + n;
    }
    link[xi].insert(xj);
}
bool check()
{
    for(int i = 1; i <= n; i++)
    {
        if(group[i] == group[i + n])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int xi, xj;
        std::cin >> xi >> xj;
        make_link(-xi, xj);
        make_link(-xj, xi);
    }
    for(int i = 1; i <= n * 2; i++)
    {
        if(ID[i] == 0)
        {
            dfs(i);
        }
    }
    if(check())
    {
        std::cout << "0\n";
    }
    else
    {
        std::cout << "1\n";
        int table[n + 1];
        std::memset(table, -1, sizeof(table));
        for(auto rbgn = SCC.rbegin(); rbgn != SCC.rend(); rbgn++)
        {
            for(auto node : *rbgn)
            {
                int boolean = 0;
                if(node > n)
                {
                    node -= n;
                    boolean++;
                }
                if(table[node] == -1)
                {
                    table[node] = boolean;
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            std::cout << table[i] << ' ';
        }
    }
    return 0;
}