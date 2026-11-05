#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 500010
int n, m, list[MAX], fenwick[MAX];
inline int XOR(int i)
{
    int ret = 0;
    while(i)
    {
        ret ^= fenwick[i];
        i -= (i & -i);
    }
    return ret;
}
void update(int i, int val)
{
    while(i <= n)
    {
        fenwick[i] ^= val;
        i += (i & -i);
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        update(i + 1, val);
        update(i + 2, val);
    }
    std::cin >> m;
    for(int i = 0; i < m; i++)
    {
        int t, a;
        std::cin >> t >> a;
        if(t == 1)
        {
            int b, c;
            std::cin >> b >> c;
            update(a + 1, c);
            update(b + 2, c);
        }
        else
        {
            std::cout << XOR(a + 1) << '\n';
        }
    }
    return 0;
}