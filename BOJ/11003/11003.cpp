#include <iostream>
#include <queue>
#include <algorithm>
struct pqn{
    int A, idx;
    bool operator<(const pqn &rhs) const{
        if(A == rhs.A)
        {
            return idx > rhs.idx;
        }
        return A > rhs.A;
    }
};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, L, s = 0;
    std::priority_queue<pqn> pq;
    std::cin >> n >> L;
    for(int e = 0; e < n; e++)
    {
        int number;
        std::cin >> number;
        pq.push({number, e});
        if(e - s >= L)
        {
            s = e - L + 1;
        }
        while(!pq.empty())
        {
            auto [N, idx] = pq.top();
            if(idx < s || e < idx)
            {
                pq.pop();
            }
            else
            {
                std::cout << N << ' ';
                break;
            }
        }
    }
    return 0;
}