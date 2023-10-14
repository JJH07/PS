#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 100000;
int n;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    for(int i = 0; i < 3; i++)
    {
        ll stk = 0, sum = 0, val;

        std::cin >> n;
        while(n--)
        {
            std::cin >> val;
            if(val > 0 && sum > 0 && sum > LONG_LONG_MAX - val)
            {
                ++stk;
            }         
            if(val < 0 && sum < 0 && sum < LONG_LONG_MIN - val)
            {
                --stk;
            }   
            sum += val;
        }
        if(stk == 0)
        {
            stk += sum;
        }
        if(stk == 0)
        {
            std::cout << "0\n";
        }
        else if(stk > 0)
        {
            std::cout << "+\n";
        }
        else
        {
            std::cout << "-\n";
        }
    }
    return 0;
}