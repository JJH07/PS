#include <iostream>
#include <vector>
#include <cmath>
#define INF 1e9
typedef long long ll;

struct  node{
    ll weight;
    ll baseused;
};
node diet(ll Day, ll Weight, ll Eat, ll Workout, ll BaseUsed, ll T)
{
    bool FLAG = false;
    while(Day--)
    {
        ll T_t = Eat - (Workout + BaseUsed);
        Weight += T_t;
        if(abs(T_t) > T)
        {
            BaseUsed += floor(((double)T_t) / 2);
        }
        if(Weight <= 0 || BaseUsed <= 0)
        {
            return {0, 0};
        }
    }
    return {Weight, BaseUsed};
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    ll Weight, Base, T, D, I, A;
    std::cin >> Weight >> Base >> T >> D >> I >> A;

    node ans = diet(D, Weight, I, A, Base, INF);
    if(ans.weight <= 0 || ans.baseused <= 0)
    {
        std::cout << "Danger Diet\n";
    }
    else
    {
        std::cout  << ans.weight << ' ' << ans.baseused << '\n';   
    }
    ans = diet(D, Weight, I, A, Base, T);
    if(ans.weight <= 0 || ans.baseused <= 0)
    {
        std::cout << "Danger Diet\n";
    }
    else
    {
        std::cout  << ans.weight << ' ' << ans.baseused << ' ' << (Base > ans.baseused  ? "YOYO\n" : "NO\n");
    }
    return 0;
}