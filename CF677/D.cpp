#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n;
        std::cin >> n;
        std::vector<int> city(n), link[n];
        std::queue<int> q;
        bool visited[n];
        std::memset(visited, 0, sizeof(visited));

        for(int i = 0; i < n; i++)
        {
            std::cin >> city[i];
        }
        int cnt = 0;
        q.push(0);
        visited[0] = 1;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            for(int i = 0; i < n; i++)
            {
                if(visited[i])
                {
                    continue;
                }
                if(city[front] != city[i])
                {
                    cnt++;
                    q.push(i);
                    visited[i] = 1;
                    link[front].push_back(i);
                }
            }
        }
        if(cnt != n - 1)
        {
            std::cout << "NO\n";
        }
        else
        {
            std::cout << "YES\n";
            for(int now = 0; now < n; now++)
            {
                for(int next : link[now])
                {
                    std::cout << now + 1 << ' ' << next + 1 << '\n';
                }
            }
        }
        
    }
    return 0;
}