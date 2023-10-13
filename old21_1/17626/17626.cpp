#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 50001
typedef std::pair<int, int> pii;
bool visited[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, ans = -1;
    std::queue<pii> q;
    std::cin >> n;
    visited[n] = true;
    q.push({n, 0});
    while(!q.empty())
    {
        auto [now, c] = q.front();
        q.pop();
        if(now == 0)
        {
            ans = c;
            break;
        }
        for(int i = 1; i * i <= now; i++)
        {
            if(!visited[now - i * i])
            {
                visited[now - i * i] = true;
                q.push({now - i * i, c + 1});
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}