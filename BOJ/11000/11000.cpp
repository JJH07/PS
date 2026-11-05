#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
struct node{
    int s, e;
    bool operator<(const node &rhs)const{
        if(s == rhs.s)
        {
            return e > rhs.e;
        }
        return s > rhs.s;
    }
};
int n;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::priority_queue<node> table;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int s, e;
        std::cin >> s >> e;
        table.push({s, e});
    }
    pq.push(0);
    while(!pq.empty())
    {
        if(table.empty())
        {
            break;
        }
        auto [x, y] = table.top();
        int min_s = pq.top();
        table.pop();
        if(min_s <= x)
        {
            pq.pop();
        }
        pq.push(y);
    }
    std::cout << pq.size() << '\n';
    return 0;
}