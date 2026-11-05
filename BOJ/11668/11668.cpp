#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define MAX 1000
typedef long long ll;
typedef std::pair<int, int> Point;
typedef std::pair<Point, Point> Pipe;

int W, P, ID[MAX * 2 + 1], GROUP[MAX * 2 + 1], ID_idx, GROUP_idx;
bool finished[MAX * 2 + 1];
std::stack<int> stk;
std::vector<int> Link[MAX * 2 + 1];
int CCW(Point a, Point b, Point c)
{
    ll ccw = 1LL * a.first * b.second + 1LL * b.first * c.second + 1LL * c.first * a.second;
    ccw -= (1LL * a.second * b.first + 1LL * b.second * c.first + 1LL * c.second * a.first);
    if(ccw > 0)
    {
        return 1;
    }
    if(ccw == 0)
    {
        return 0;
    }
    return -1;
}
bool Intersect(Pipe x, Pipe y)
{
    auto [a, b] = x;
    auto [c, d] = y;
    int ccw1 = CCW(a, b, c) * CCW(a, b, d);
    int ccw2 = CCW(c, d, a) * CCW(c, d, b);
    if(ccw1 == 0 && ccw2 == 0)
    {
        if(a > b)
        {
            std::swap(a, b);
        }
        if(c > d)
        {
            std::swap(c, d);
        }
        return c <= b && a <= d;
    }
    return ccw1 <= 0 && ccw2 <= 0;
}
int Make_SCC(int idx)
{
    ID[idx] = ++ID_idx;
    stk.push(idx);

    int parent = ID[idx];
    for(int next : Link[idx])
    {
        if(ID[next] == 0)
        {
            parent = std::min(parent, Make_SCC(next));
        }
        else if(!finished[next])
        {
            parent = std::min(parent, ID[next]);
        }
    }
    if(parent == ID[idx])
    {
        ++GROUP_idx;
        while(!stk.empty())
        {
            int top = stk.top();
            stk.pop();
            GROUP[top] = GROUP_idx;
            finished[top] = true;
            if(top == idx)
            {
                break;
            }
        }
    }
    return parent;
}
void Linking(int x, int y)
{
    if(x < 0)
    {
        x = -x + P; 
    }
    if(y < 0)
    {
        y = -y + P;
    }
    Link[x].push_back(y);
    Link[y].push_back(x);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    Point Source[MAX + 1];
    Pipe Pipes[MAX + 1];

    std::cin >> W >> P;
    for(int i = 1; i <= W; i++)
    {
        std::cin >> Source[i].first >> Source[i].second;
    }
    for(int i = 1; i <= P; i++)
    {
        int s;
        std::cin >> s >> Pipes[i].second.first >> Pipes[i].second.second;
        Pipes[i].first = Source[s];
    }
    for(int i = 1; i < P; i++)
    {
        for(int j = i + 1; j <= P; j++)
        {
            if(Intersect(Pipes[i], Pipes[j]) && (Pipes[i].first != Pipes[j].first))
            {
                Linking(-i, j);
                Linking(i, -j);
            }
        }
    }
    for(int i = 1; i <= P * 2; i++)
    {
        if(ID[i] == 0)
        {
            Make_SCC(i);
        }
    }
    bool ans = true;
    for(int i = 1; i <= P; i++)
    {
        if(GROUP[i] == GROUP[i + P])
        {
            ans = false;
            break;
        }
    }
    std::cout << (ans ? "possible\n" : "impossible\n");
    return 0;
}