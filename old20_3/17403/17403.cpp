#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 1001
typedef long long ll;

struct node{
    int x, y, p, q, idx;
    node(int X, int Y) : x(X), y(Y), p(1), q(0) {}
    bool operator<(const node &rhs) const{
        if(1LL * rhs.p * q != 1LL * p * rhs.q)
        {
            return rhs.p * q < rhs.q * p;
        }
        if(y != rhs.y)
        {
            return y < rhs.y;
        }
        return x < rhs.x;
    }
};
int n, LEVEL[MAX];
bool USED[MAX];
std::pair<int, int> POS[MAX];
ll CCW(const node& A, const node& B, const node& C)
{
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
}
bool convex_hull(int step)
{
    std::vector<node> list;
    for(int i = 0; i < n; i++)
    {
        if(!USED[i])
        {
            list.push_back(node(POS[i].first, POS[i].second));
            list.back().idx = i;
        }
    }
    int list_sz = (int)list.size();
    if(list_sz <= 2)
    {
        return false;
    }
    std::sort(list.begin(), list.end());
    for(int i = 1; i < list_sz; i++)
    {
        list[i].p = list[i].x - list[0].x;
        list[i].q = list[i].y - list[0].y;
    }
    std::sort(list.begin() + 1, list.end());

    std::stack<int> stk;
    stk.push(0);
    stk.push(1);
    int idx = 2;
    while(idx < list_sz)
    {
        while(stk.size() >= 2)
        {
            int first, second;
            second = stk.top();
            stk.pop();
            first = stk.top();
            if(CCW(list[first], list[second], list[idx]) > 0)
            {
                stk.push(second);
                break;
            }
        }
        stk.push(idx++);
    }
    if(stk.size() <= 2)
    {
        return false;
    }
    while(!stk.empty())
    {
        int top = stk.top();
        stk.pop();
        USED[list[top].idx] = true;
        LEVEL[list[top].idx] = step;
    }
    return true;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> POS[i].first >> POS[i].second;
    }
    
    int step = 0;
    while(convex_hull(++step))
    {}
    for(int i = 0; i < n; i++)
    {
        std::cout << LEVEL[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}