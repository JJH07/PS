#include <bits/stdc++.h>
typedef std::pair<int, int> pii;

pii find(int n, int k)
{
    for(int a = 0; a <= n; a++)
    {
        int b = n - a;
        if(a * b < k)
        {
            continue;
        }
        return {a, b};
    }
    return {-1, -1};
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;
    auto [a, b] = find(n, k);
    if(a == -1)
    {
        std::cout << "-1\n";
        return 0;
    }
    std::vector<int> pos(a + 1, 0);
    for(int i = 0; i < b; i++)
    {
        int bPos = std::min(k, a);
        pos[bPos]++;
        k -= bPos;
    }
    for(int i = 0; i < pos[0]; i++)
    {
        std::cout << 'B';
    }
    for(int A = 1; A <= a; A++)
    {
        std::cout << 'A';
        for(int i = 0; i < pos[A]; i++)
        {
            std::cout << 'B';
        }
    }
    return 0;
}