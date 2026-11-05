#include <iostream>
#include <cstring>
#include <queue>

struct employee{
    int WorkDay, Hurry, q_idx, idx;
    bool operator<(const employee &rhs) const{
        if(WorkDay == rhs.WorkDay)
        {
            if(Hurry == rhs.Hurry)
            {
                return q_idx > rhs.q_idx;
            }
            return Hurry < rhs.Hurry;
        }
        return WorkDay < rhs.WorkDay;
    }
};
int n, m, k;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> k;
    std::queue<employee> q[m];
    std::priority_queue<employee> pq;
    for(int i = 0; i < n; i++)
    {
        int D, H;
        std::cin >> D >> H;
        q[i % m].push({D, H, i % m, i});
    }
    for(int i = 0; i < m; i++)
    {
        if(!q[i].empty())
        {
            pq.push(q[i].front());
            q[i].pop();
        }
    }
    int count = 0;
    while(!pq.empty())
    {
        employee now = pq.top();
        pq.pop();
        if(now.idx == k)
        {
            break;
        }
        count++;
        if(!q[now.q_idx].empty())
        {
            pq.push(q[now.q_idx].front());
            q[now.q_idx].pop();
        }
    }
    std::cout << count << '\n';
    return 0;
}