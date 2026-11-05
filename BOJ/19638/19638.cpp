#include <iostream>
#include <vector>
#include <queue>
#define INF 1e12;
typedef long long ll;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, T;
    ll H;
    std::vector<ll> giants;
    std::priority_queue<std::pair<ll,  int>> pq;
    std::cin >> n >> H >> T;
    for(int i = 0; i < n; i++)
    {
        ll height;
        std::cin >> height;
        giants.push_back(height);
        if(height >= H)
        {
            pq.push({height, i});
        }
    }
    int killed = 0;
    while(!pq.empty())
    {
        if(killed == T)
        {
            break;
        }
        auto [height, idx] = pq.top();
        if(height == 1)
        {
            break;
        }
        pq.pop();
        killed++;
        height /= 2;
        giants[idx] = height;
        if(height >= H)
        {
            pq.push({height, idx});
        }
    }
    if(pq.empty())
    {
        std::cout << "YES\n" << killed;
    }
    else
    {
        std::cout << "NO\n" << pq.top().first;
    }
    
    return 0;
}