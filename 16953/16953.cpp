#include <iostream>
#include <queue>
typedef long long ll;
ll A, B;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::queue<std::pair<ll, int>> q;
    std::cin >> A >> B;
    int ans = -1;
    q.push({A, 1});
    while(!q.empty())
    {
        auto [now, c] = q.front();
        q.pop();
        if(now > B)
        {
            continue;
        }
        if(now == B)
        {
            ans = c;
            break;
        }
        q.push({now * 2, c + 1});
        q.push({now * 10 + 1, c + 1});
    }
    std::cout << ans << '\n';
    return 0;
}