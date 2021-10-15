#include <bits/stdc++.h>
#define MAX 1000000
typedef long long ll;

int n, Fenwick[MAX + 1];
void update(int idx, ll val)
{
    while(idx <= n)
    {
        ++Fenwick[idx];
        idx += (idx & -idx);
    }
}
ll sum(int idx)
{
    ll sum = 0;
    while(idx > 0)
    {
        sum += Fenwick[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll answer = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        answer += i - sum(number);
        update(number, 1);
    }
    std::cout << answer << '\n';
    return 0;
}