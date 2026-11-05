#include <iostream>
#include <vector>

std::vector<int> link[100001];
bool visited[100001];
int counting[100001];
int dfs(int now)
{
    int &ret = counting[now];
    ret = 1;
    for(auto next : link[now])
    {
        if(!visited[next])
        {
            visited[next] = 1;
            ret += dfs(next);
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, R, Q;
    std::cin >> N >> R >> Q;
    for(int i = 0; i < N - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }
    visited[R] = 1;
    dfs(R);
    while(Q--)
    {
        int query;
        std::cin >> query;
        std::cout << counting[query] << '\n';
    }
    return 0;
}