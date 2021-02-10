#include <iostream>
#include <stack>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, P, ans = 0;
    std::stack<int> line[7];
    std::cin >> N >> P;
    while(N--)
    {
        int idx, p;
        std::cin >> idx >> p;
        while(!line[idx].empty())
        {
            if(line[idx].top() <= p)
            {
                break;
            }
            line[idx].pop();
            ans++;
        }
        if(line[idx].empty() || line[idx].top() != p)
        {
            line[idx].push(p);
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
