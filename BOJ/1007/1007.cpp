#include <iostream>
#include <cmath>
#define MAX 20
typedef std::pair<int, int> pii;
int n;
double ans;
pii list[MAX], tot, P;
pii operator+(const pii &a, const pii &b)
{
    return {a.first + b.first, a.second + b.second};
}
pii operator-(const pii &a, const pii &b)
{
    return {a.first - b.first, a.second - b.second};
}
double get_dist(const pii &a)
{
    return sqrt(1LL * a.first * a.first + 1LL * a.second * a.second);
}
void pick(int picked, int idx, pii P)
{
    if(picked == n / 2)
    {
        ans = std::min(ans, get_dist(P - (tot - P)));
    }
    else
    {
        for(int i = idx; i < n; i++)
        {
            pick(picked + 1, i + 1, P + list[i]);
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(12);
    int t;
    std::cin >> t;
    while(t--)
    {
        tot = {0, 0};
        P = {0, 0};
        ans = 1e9;
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            std::cin >> list[i].first >> list[i].second;
            tot.first += list[i].first;
            tot.second += list[i].second;
        }
        pick(0, 0, {0, 0});
        std::cout << ans << '\n';
    }
    return 0;
}