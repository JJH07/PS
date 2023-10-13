#include <iostream>
#include <queue>
#define MAX 100000
typedef std::pair<int, int> pii;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::priority_queue<pii> pq;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        if(x != 0)
        {
            int ABS = x < 0 ? -x : x;
            pq.push({-ABS, -x});
        }
        else if(pq.empty())
        {
            std::cout << "0\n";
        }
        else
        {
            std::cout << -pq.top().second << '\n';
            pq.pop();
        }
    }
    return 0;
}