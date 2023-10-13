#include <iostream>
#include <vector>
#include <queue>

int n;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n, shelf[51], ans = 0;
        std::queue<int> q;
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            std::cin >> shelf[i];
            if(shelf[i] == 1)
            {
                q.push(i);
            }
        }
        int now = q.front();
        q.pop();
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ans += (front - now - 1);
            now = front;
        }
        std::cout << ans << '\n';
    }
    return 0;
}