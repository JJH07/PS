#include <iostream>
#include <queue>
#define MAX 1500
struct pqn{
    int x, y, val;
    bool operator<(const pqn &rhs)const{
        return val < rhs.val;
    }
};
int n, map[MAX][MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::priority_queue<pqn> pq;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> map[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        pq.push({n - 1, i, map[n - 1][i]});
    }
    for(int i = 1; i < n; i++)
    {
        auto [x, y, v] = pq.top();
        pq.pop();
        if(x > 0)
        {
            pq.push({x - 1, y, map[x - 1][y]});
        }
    }
    std::cout << pq.top().val << '\n';
    return 0;
}