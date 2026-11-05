#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
typedef long long ll;
int Prime[100];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int k, n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::cin >> k >> n;
    for(int i = 0; i < k; i++)
    {
        std::cin >> Prime[i];
        pq.push(Prime[i]);
    }
    for(int i = 1; i < n; i++)
    {
        int now = pq.top();
        while(!pq.empty())
        {
            if(now != pq.top())
            {
                break;
            }
            pq.pop();
        }
        for(int j = 0; j < k; j++)
        {
            ll next = 1ll * now * Prime[j];
            if(next >= 1ll * INT_MAX)
            {
                break;
            }
            pq.push(next);
        }
    }
    std::cout << pq.top() << '\n';
    return 0;
}