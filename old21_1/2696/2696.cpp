#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int m;
        std::priority_queue<int> l;
        std::priority_queue<int, std::vector<int>, std::greater<int>> r;
        std::vector<int> ans;
        std::cin >> m;
        l.push(INT_MIN);
        r.push(INT_MAX);
        for(int i = 1; i <= m; i++)
        {
            int number;
            std::cin >> number;
            l.push(number);
            while(l.size() > r.size())
            {
                int L = l.top();
                int R = r.top();
                if(L > R)
                {
                    l.push(R);
                    r.push(L);
                    l.pop();
                    r.pop();
                }
                else
                {
                    r.push(L);
                    l.pop();
                }
            }
            if(i % 2)
            {
                ans.push_back(r.top());
            }
        }
        int sz = (int)ans.size();
        std::cout << sz << '\n';
        for(int i = 1; i <= sz; i++)
        {
            std::cout << ans[i - 1] << (i % 10 ? ' ' : '\n');
        }
    }
    return 0;
}