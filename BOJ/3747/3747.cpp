#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#define MAX 2001

int n, m, ID[MAX], ID_idx, GROUP[MAX], GROUP_idx;
bool finished[MAX];
std::vector<int> link[MAX];
std::stack<int> stk;
void push_link(int x, int y)
{
    if(x < 0)
    {
        x = -x + n;
    }
    if(y < 0)
    {
        y = -y + n;
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
            GROUP[top] = GROUP_idx;
            finished[top] = true;
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

    while(!(std::cin >> n >> m).eof())
    {
        std::memset(ID, 0, sizeof(ID));
        std::memset(GROUP, 0, sizeof(GROUP));
        std::memset(finished, 0, sizeof(finished));
        ID_idx = 0;
        GROUP_idx = 0;
        for(int i = 1; i <= MAX; i++)
        {
            link[i].clear();
        }

        for(int i = 0; i < m; i++)
        {
            int x, y;
            std::cin >> x >> y;
            push_link(-x, y);
            push_link(-y, x);
        }
        for(int i = 1; i <= n * 2; i++)
        {
            if(ID[i] == 0)
            {
                Make_SSC(i);
            }
        }
        bool FLAG = true;
        for(int i = 1; i <= n; i++)
        {
            if(GROUP[i] == GROUP[i + n])
            {
                FLAG = false;
                break;
            }
        }
        std::cout << FLAG << '\n';
    }
    return 0;
}