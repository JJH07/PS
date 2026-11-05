#include <bits/stdc++.h>
typedef std::pair<int, int> pii;
const int MAX = 500001;

int n, k, dist[MAX][2];
std::queue<pii> q;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k;
    
    std::memset(dist, -1, sizeof(dist));

    dist[n][0] = 0;
    q.push(std::make_pair(n, 0));
    while(!q.empty())
    {
        auto [pos, t] = q.front();
        q.pop();

        for(auto next : {pos - 1, pos + 1, pos * 2})
        {
            if(next < 0 || next >= MAX || dist[next][!t] != -1)
            {
                continue;
            }
            dist[next][!t] = dist[pos][t] + 1;
            q.push(std::make_pair(next, !t));
        }
    }
    int ans = -1;
    for(int pos = k, cnt = 0; pos < MAX; pos += ++cnt)
    {
        if(dist[pos][cnt % 2] == -1)
        {
            continue;
        }
        if(dist[pos][cnt % 2] <= cnt)
        {
            ans = cnt;
            break;
        }
    }
    std::cout << ans << '\n';
    return 0;
}