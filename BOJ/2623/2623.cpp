#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 1001
int n, m, degree[MAX];
std::vector<int> link[MAX], ans;
std::queue<int> q;
bool topological()
{
    for(int i = 0; i < n; i++)
    {
        if(q.empty())
        {
            return false;
        }
        int now = q.front();
        q.pop();
        ans.push_back(now);
        for(int next : link[now])
        {
            degree[next]--;
            if(degree[next] == 0)
            {
                q.push(next);
            }
        }
    }
    return true;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int c, pre;
        std::cin >> c >> pre;
        for(int j = 0; j < c - 1; j++)
        {
            int now;
            std::cin >> now;
            link[pre].push_back(now);
            degree[now]++;
            pre = now;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(degree[i] == 0)
        {
            q.push(i);
        }
    }
    if(topological())
    {
        for(auto x : ans)
        {
            std::cout << x << '\n';
        }
    }
    else
    {
        std::cout << "0\n";
    }
    
    return 0;
}