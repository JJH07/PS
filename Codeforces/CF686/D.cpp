#include <iostream>
#include <map>
#include <cmath>
#define MAX 1e5
typedef long long ll;
bool is_Prime[(int)MAX + 1];
std::map<ll, int> list;

void make_list(ll n)
{
    for(int i = 2; i <= MAX; i++)
    {
        if(i > n)
        {
            break;
        }
        if(is_Prime[i] || (n % i) > 0)
        {
            continue;
        }
        while(n % i == 0)
        {
            if(list.find(i) == list.end())
            {
                list.insert({i, 1});
            }
            else
            {
                list[i] += 1;
            }
            n /= i;
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    is_Prime[0] = true;
    is_Prime[1] = true;
    for(int i = 2; i <= MAX; i++)
    {
        if(!is_Prime[i])
        {
            for(int next = i + i; next <= MAX; next += i)
            {
                is_Prime[next] = true;
            }
        }
    }
    int t;
    std::cin >> t;
    while(t--)
    {
        list.clear();
        ll n;
        std::cin >> n;
        make_list(n);
        ll divisor, cnt = 0;
        for(auto x : list)
        {
            if(x.second > cnt)
            {
                divisor = x.first;
                cnt = x.second;
            }
        }
        if(cnt <= 1)
        {
            std::cout << "1\n" << n << '\n';
        }
        else
        {
            std::cout << cnt << '\n';
            for(int i = 0; i < cnt - 1; i++)
            {
                std::cout << divisor << ' ';
                n /= divisor;
            }
            std::cout << n << '\n';
        }
        
    }
    return 0;
}