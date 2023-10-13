#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
const int MAX = 2e5;
std::vector<ll> odd, even;
int odd_idx, even_idx;
ll Alice_P, Bob_P;
ll Pick_odd()
{
    if(odd_idx == -1)
    {
        return 0;
    }
    return odd[odd_idx];
}
ll Pick_even()
{
    if(even_idx == -1)
    {
        return 0;
    }
    return even[even_idx];
}
void Alice()
{
    ll o = Pick_odd();
    ll e = Pick_even();
    if(o > e)
    {
        odd_idx--;
    }
    else
    {
        Alice_P += e;
        even_idx--;
    }
}
void Bob()
{
    ll o = Pick_odd();
    ll e = Pick_even();
    if(e > o)
    {
        even_idx--;
    }
    else
    {
        Bob_P += o;
        odd_idx--;
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n;
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            ll t;
            std::cin >> t;
            if(t % 2)
            {
                odd.push_back(t);
            }
            else
            {
                even.push_back(t);
            }
        }
        std::sort(odd.begin(), odd.end());
        std::sort(even.begin(), even.end());
        odd_idx = odd.size() - 1;
        even_idx = even.size() - 1;
        Alice_P = 0;
        Bob_P = 0;
        for(int i = 0; i < n; i++)
        {
            if(i % 2)
            {
                Bob();
            }
            else
            {
                Alice();
            }
        }
        if(Alice_P == Bob_P)
        {
            std::cout << "Tie\n";
        }
        else
        {
            std::cout << (Alice_P > Bob_P ? "Alice\n" : "Bob\n");
        }
        
        odd.clear();
        even.clear();
    }
    return 0;
}