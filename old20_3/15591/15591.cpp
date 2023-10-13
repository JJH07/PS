#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 5001
#define INF 1e12
typedef long long ll;

int n, q;
std::vector<std::pair<int, ll>> USADO[MAX];
int find(int idx, ll v)
{   
    std::queue<std::pair<int, ll>> q;
    bool visited[n + 1];
    int ret = 0;
    std::memset(visited, 0, sizeof(visited));

    visited[idx] = 1;
    for(auto [nidx, usado] : USADO[idx])
    {
        visited[nidx] = 1;
        q.push({nidx, usado});
    }
    while(!q.empty())
    {
        auto [now, W] = q.front();
        q.pop();
        if(W >= v)
        {
            ret++;
        }
        for(auto [nidx, usado] : USADO[now])
        {
            if(!visited[nidx])
            {
                visited[nidx] = 1;
                q.push({nidx, std::min(W, usado)});
            }
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> q;
    for(int i = 0; i < n - 1; i++)
    {
        int P, Q;
        ll R;
        std::cin >> P >> Q >> R;
        USADO[P].push_back({Q, R});
        USADO[Q].push_back({P, R});
    }
    while(q--)
    {
        int k;
        ll v, ans = 0;
        std::cin >> k >> v;
        std::cout << find(v, k) << '\n';
    }
    return 0;
}