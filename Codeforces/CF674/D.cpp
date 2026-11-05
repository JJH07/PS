#include <iostream>
#include <set>
typedef long long ll;
ll list[200001];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, ans = 0;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> list[i];
    }
    std::set<ll> s;
    ll sum = 0;
    s.insert(0);
    for(int i = 1; i <= n; i++)
    {
        sum += list[i];
        if(s.find(sum) == s.end())
        {
            s.insert(sum);
        }
        else
        {
            ans++;
            s.clear();
            sum = list[i];
            s.insert(0);
            s.insert(sum);
        }
    }
    std::cout << ans << '\n';
    return 0;
}