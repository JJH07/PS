#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

const int MAX = 10000;
int n, m, ID[MAX * 2 + 1], ID_cnt, group[MAX * 2 + 1];
bool finish[MAX * 2 + 1];
std::vector<int> link[MAX * 2 + 1];
std::stack<int> stk;
std::vector<std::vector<int>> SCC;

void link_push(int xi, int xj)
{
    if(xi < 0)
    {
        xi = -xi + n;
    }
    if(xj < 0)
    {
        xj = -xj + n;
    }
    link[xi].push_back(xj);
}
int Make_SCC(int idx)
{
    stk.push(idx);
    ID[idx] = ++ID_cnt;

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
            group[top] = grp;
            scc.push_back(top);
            finish[top] = 1;
            if(top == idx)
            {
                break;
            }
        }
        SCC.push_back(scc);
    }
    return parent;
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
        link_push(-xi, xj);
        link_push(-xj, xi);
    }
    for(int i = 1; i <= n * 2; i++)
    {
        if(ID[i] == 0)
        {
            Make_SCC(i);
        }
    }
    if(check())
    {
        std::cout << "0\n";
    }
    else
    {
        std::cout << "1\n";

        int table[MAX + 1];
        std::memset(table, -1, sizeof(table));
        for(auto rbgn = SCC.rbegin(); rbgn != SCC.rend(); rbgn++)
        {
            for(int node : *rbgn)
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