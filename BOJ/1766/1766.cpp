#include <iostream>
#include <queue>
#include <vector>
int n, m, check[32001];
std::vector<int> next[32001];
std::priority_queue<int> pq;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int A, B;
        std::cin >> A >> B;
        next[A].push_back(B);
        check[B]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(check[i] == 0)
        {
            pq.push(-i);
        }
    }
    while(!pq.empty())
    {
        int top = -pq.top();
        pq.pop();
        std::cout << top << ' ';
        for(int x : next[top])
        {
            check[x]--;
            if(check[x] == 0)
            {
                pq.push(-x);
            }
        }
    }
    return 0;
}