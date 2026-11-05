#include <iostream>
#include <queue>
#include <vector>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n, idx = 1;
        std::queue<int> q;
        std::cin >> n;
        for(int i = 1; i <= n; i++)
        {
            q.push(i);
        }
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            if(front == idx)
            {
                q.push(front);
            }
            else
            {
                std::cout << front << ' ';
                idx++;
            }
        }
        std::cout << '\n';
    }
    return 0;
}