#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#define MAX 2001

int n, m, ID[MAX], ID_idx, group[MAX], group_idx;
bool finish[MAX];
std::vector<std::vector<int>> link;
std::stack<int> stk;

void Make_Link(int a, int b)
{
    if(a < 0)
    {
        a = n - a;
    }
    if(b < 0)
    {
        b = n - b;
    }
    link[a].push_back(b);
}
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
        while(!stk.empty())
        {
            int top = stk.top();
            stk.pop();
            finish[top] = true;
            group[top] = group_idx;
            if(top == idx)
            {
                break;
            }
        }
        group_idx++;
    }
    return parent;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    while(!(std::cin >> n >> m).eof())
    {
        ID_idx = 0;
        group_idx = 1;
        link.clear();
        link.resize(n * 2 + 1);
        std::memset(ID, 0, sizeof(ID));
        std::memset(group, 0, sizeof(group));
        std::memset(finish, 0, sizeof(finish));
        for(int i = 0; i < m; i++)
        {
            int a, b;
            std::cin >> a >> b;
            Make_Link(-a, b);
            Make_Link(-b, a);
        }
        Make_Link(-1, 1);
        for(int i = 1; i <= n * 2; i++)
        {
            if(ID[i] == 0)
            {
                Make_SCC(i);
            }
        }
        bool NO = false;
        for(int i = 1; i <= n; i++)
        {
            if(group[i] == group[i + n])
            {
                NO = true;
                break;
            }
        }
        std::cout << (NO ? "no\n" : "yes\n");
    }
    return 0;
}