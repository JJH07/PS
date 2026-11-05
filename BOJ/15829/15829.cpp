#include <iostream>
#include <string>
typedef long long ll;
const ll MUL = 31;
const ll MOD = 1234567891;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    ll L, ans = 0, m = 1;
    std::string str;
    std::cin >> L >> str;
    for(auto c : str)
    {
        ans = (ans + (m * (c - 'a' + 1)) % MOD) % MOD;
        m = (m * MUL) % MOD;
    }
    std::cout << ans << '\n';
    return 0;
}