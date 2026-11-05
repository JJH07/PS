#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int n, h;
std::vector<int> flr, cil;

bool compare(const int &a, const int &b)
{
    return a > b;
}
int flr_drill(int height)
{
    int l = 0, r = n / 2 - 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(flr[mid] >= height)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}
int cil_drill(int height)
{
    int l = 0, r = n / 2 - 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(cil[mid] >= height)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return (n / 2) - l;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> h;
    
    int n2 = n / 2, min_val  = INT_MAX, cnt = 0;
    
    for(int i = 0; i < n2; i++)
    {
        int a, b;
        std::cin >> a >> b;
        flr.push_back(a);
        cil.push_back(h - b);
    }
    sort(flr.begin(), flr.end(), compare);
    sort(cil.begin(), cil.end(), compare);
    for(int i = 1; i <= h; i++)
    {
        int now_brick = flr_drill(i) + cil_drill(i);
        if(now_brick == min_val)
        {
            cnt++;
        }
        else if(now_brick < min_val)
        {
            min_val = now_brick;
            cnt = 1;
        }
    }
    std::cout << min_val << ' ' << cnt << '\n';

    return 0;
}
