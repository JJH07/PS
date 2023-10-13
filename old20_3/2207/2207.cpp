#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#define MAX 20001

int n, m, ID[MAX], ID_idx, GROUP[MAX], GROUP_idx;
bool finished[MAX];
std::vector<int> link[MAX];
std::stack<int> stk;
void push_link(int x, int y)
{
    if(x < 0)
    {
        x = -x + m;
    }
    if(y < 0)
    {
        y = -y + m;
    }
    link[x].push_back(y);
}
int Make_SSC(int idx)
{
    ID[idx] = ++ID_idx;
    stk.push(idx);

    int parent = ID[idx];
    for(int next : link[idx])
    {
        if(ID[next] == 0)
        {
            parent = std::min(parent, Make_SSC(next));
        }
        else if(!finished[next])
        {
            parent = std::min(parent, ID[next]);
        }
    }
    if(parent == ID[idx])
    {
        GROUP_idx++;
        while(!stk.empty())
        {
            int top = stk.top();
            stk.pop();
            finished[top] = true;
            GROUP[top] = GROUP_idx;
            if(top == idx)
            {
                break;
            }
        }
    }
    return parent;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        push_link(-x, y);
        push_link(-y, x);
    }
    for(int i = 1; i <= m * 2; i++)
    {
        if(ID[i] == 0)
        {
            Make_SSC(i);
        }
    }
    bool FLAG = false;
    for(int i = 1; i <= m; i++)
    {
        if(GROUP[i] == GROUP[i + m])
        {
            FLAG = true;
            break;
        }
    }
    std::cout << (FLAG ? "OTL\n" : "^_^\n");
    return 0;
}