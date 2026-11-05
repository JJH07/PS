#include <iostream>
#include <vector>
#include <string>
#include <cstring>
typedef long long ll;
const ll MOD = 1e9 + 7;

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    ll a = 0, b = 0, c = 0, q = 1;
    std::string str;
    std::cin >> n >> str;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'a')
        {
            a = (a + q) % MOD;
        }
        else if(str[i] == 'b')
        {
            b = (a + b) % MOD;
        }
        else if(str[i] == 'c')
        {
            c = (b + c) % MOD;
        }
        else
        {
            c = (c * 3 + b) % MOD;
            b = (b * 3 + a) % MOD;
            a = (a * 3 + q) % MOD; 
            q = (q * 3) % MOD;
        }
    }
    std::cout << c << '\n';
    return 0;
}