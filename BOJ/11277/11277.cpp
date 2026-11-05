#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <set>

int n, m, ID[41], ID_cnt, indegree[41];
std::stack<int> stk;
bool finished[41];

std::set<int> link[41];
std::vector<std::vector<int>> SCC;
bool get_ans()
{
    bool check[n * 2 + 1];
    for(auto c : SCC)
    {
        std::memset(check, 0, sizeof(check));
        for(auto x : c)
        {
            check[x] = 1;
        }
        for(int i = 1; i <= n; i++)
        {
            if(check[i] == 1 && check[i + n] == 1)
            {
                return 0;
            }
        }
    }
    return 1;
}
int dfs(int idx)
{
    ID[idx] = ++ID_cnt;
    stk.push(idx);

    int parent = ID[idx];
    
    for(int next : link[idx])
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
        while(1)
        {
            int top = stk.top();
            stk.pop();
            finished[top] = 1;
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
void make_boolean(int xi, int xj)
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
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int xi, xj;
        std::cin >> xi >> xj;
        make_boolean(-xi, xj);
        make_boolean(-xj, xi);
    }
    for(int i = 1; i <= n * 2; i++)
    {
        if(ID[i] == 0)
        {
            dfs(i);
        }
    }
    std::cout << get_ans() << '\n';
    return 0;
}