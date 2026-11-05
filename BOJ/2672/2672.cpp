#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 31
typedef long long ll;
struct node
{
    int x, y1, y2, end;
    bool operator<(const node &rhs)const{
        if(x == rhs.x)
        {
            return end < rhs.end;
        }
        return x < rhs.x;
    }
};
std::vector<node> list;
int line[20001];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        double x, y, w, h;
        std::cin >> x >> y >> w >> h;
        int int_x = x * 10;
        int int_y = y * 10;
        int int_w = w * 10;
        int int_h = h * 10;
        list.push_back({int_x, int_y, int_y + int_h, 1});
        list.push_back({int_x + int_w, int_y, int_y + int_h, -1});
    }
    std::sort(list.begin(), list.end());
    ll ans = 0, W = 0;
    for(auto x : list)
    {
        int H = 0;
        for(int i = 0; i <= 20000; i++)
        {
            if(line[i] > 0)
            {
                ++H;
            }
        }
        ans += H * (x.x - W);
        for(int i = x.y1 + 1; i <= x.y2; i++)
        {
            line[i] += x.end;
        }
        W = x.x;
    }
    if(ans % 100 > 0)
    {
        std::cout << std::fixed;
        std::cout.precision(2);
        std::cout << ans / 100.0 << '\n';
    }
    else
    {
        std::cout << (int)ans / 100 << '\n';
    }
    return 0;
}