#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>

typedef long long ll;
const int MAX = 500001;

int n, m, S, P, ID[MAX], ID_cnt, group[MAX], SCC_cnt;
ll ATM[MAX], group_ATM[MAX], dp[MAX];
std::vector<int> road[MAX];
std::set<int> group_link[MAX];
bool finished[MAX];
std::stack<int> stk;

int Make_SCC(int idx)
{
    ID[idx] = ++ID_cnt;
    stk.push(idx);

    int parent = ID[idx];
    for(auto next : road[idx])
    {
        if(ID[next] == 0)
        {
            parent = std::min(parent, Make_SCC(next));
        }
        else if(!finished[next])
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
            finished[top] = 1;
            group[top] = SCC_cnt;
            group_ATM[SCC_cnt] += ATM[top];
            if(top == idx)
            {
                break;
            }
        }
        SCC_cnt++;
    }
    return parent;
}
ll solve(int idx)
{
    ll &ret = dp[idx];
    if(ret != -1)
    {
        return ret;
    }
    ll tmp = 0;
    for(auto next : group_link[idx])
    {
        tmp = std::max(tmp, solve(next));
    }
    if(tmp == 0)
    {
        return ret = finished[idx] ? group_ATM[idx] : 0;
    }
    return ret = tmp + group_ATM[idx];
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));

    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        road[a].push_back(b);
    }
    for(int i = 1; i <= n; i++)
    {
        std::cin >> ATM[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(ID[i] == 0)
        {
            Make_SCC(i);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int next : road[i])
        {
            if(group[i] == group[next])
            {
                continue;
            }
            group_link[group[i]].insert(group[next]);
        }
    }
    std::cin >> S >> P;
    std::memset(finished, 0, sizeof(finished));
    for(int i = 0; i < P; i++)
    {
        int idx;
        std::cin >> idx;
        finished[group[idx]] = 1;
    }
    std::cout << solve(group[S]) << '\n';
    return 0;
}