#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>

struct node{
    int x, y, p, q;
    node(int A, int B) : x(A), y(B), p(1), q(0){}
    bool operator<(const node &rhs) const{
        if(q * rhs.p != p * rhs.q)
        {
            return  q * rhs.p < p * rhs.q;
        }
        if(y != rhs.y)
        {
            return y < rhs.y;
        }
        return x < rhs.x;
    }
};
int n, l;
std::vector<node> building;
std::stack<int> stk;
int ccw(const node &A, const node &B, const node &C)
{
    return A.x * B.y + B.x * C.y + C.x * A.y - A.y * B.x - B.y * C.x - C.y * A.x;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> l;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        building.push_back(node(x, y));
    }
    std::sort(building.begin(), building.end());
    for(int i = 1; i < n; i++)
    {
        building[i].p = building[i].x - building[0].x;
        building[i].q = building[i].y - building[0].y;
    }
    std::sort(building.begin() + 1, building.end());
    
    stk.push(0);
    stk.push(1);
    int idx = 2;
    while(idx < n)
    {
        while(stk.size() > 2)
        {
            int second = stk.top();
            stk.pop();
            int first = stk.top();
            if(ccw(building[first], building[second], building[idx]) > 0)
            {
                stk.push(second);
                break;
            }
        }
        stk.push(idx++);
    }
    std::vector<std::pair<int, int>> list;
    int sz = (int)stk.size();
    while(!stk.empty())
    {
        int top = stk.top();
        stk.pop();
        list.push_back({building[top].x, building[top].y});
    }
    double ans = 3.141592 * 2.0 * l + sqrt(pow(list[sz - 1].first - list[0].first, 2) + pow(list[sz - 1].second - list[0].second, 2));
    for(int i = 0; i < sz - 1; i++)
    {
        ans += sqrt(pow(list[i + 1].first - list[i].first, 2) + pow(list[i + 1].second - list[i].second, 2));
    }
    std::cout << round(ans) << '\n';
    return 0;
}