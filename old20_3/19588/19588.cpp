#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
typedef long long ll;
typedef std::pair<ll, ll> pll;

int n, m;
ll XOR[MAX], SUM[MAX];
pll list[MAX];
bool comp(const pll &a, const pll &b)
{
    return a.first > b.first;
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld %lld", &list[i].first, &list[i].second);
    }
    std::sort(list + 1, list + n + 1, comp);
    for(int i = 1; i <= n; i++)
    {
        XOR[i] = XOR[i - 1] ^ list[i].second;
    }
    for(int i = m; i <= n; i++)
    {
        SUM[i] = SUM[i - m] + (XOR[i - m] ^ XOR[i]);
    }
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%lld\n", SUM[b + a * m] - SUM[b]);
    }
    return 0;
}