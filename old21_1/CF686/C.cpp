#include <iostream>
#include <map>

#define MAX 200000
int n, seq[MAX + 1];
int next_IDX(int idx, int x)
{
    for(int i = idx + 1; i <= n; i++)
    {
        if(seq[i] == x)
        {
            return i;
        }
    }
    return n + 1;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        std::map<int, int> m;
        std::cin >> n;
        std::cin >> seq[1];
        m.insert({seq[1], 0});
        for(int i = 2; i <= n; i++)
        {
            std::cin >> seq[i];
            if(seq[i] != seq[i - 1])
            {
                if(m.find(seq[i]) == m.end())
                {
                    m.insert({seq[i], 1});
                }
                else
                {
                    m[seq[i]] += 1;
                }
            }
        }
        int ans = MAX;
        for(auto x : m)
        {
            int check = x.second;
            if(x.first != seq[n])
            {
                check += 1;
            }
            ans = std::min(ans, check);
        }
        std::cout << ans << '\n';
    }
    return 0;
}