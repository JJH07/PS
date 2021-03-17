#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 100001
typedef long long ll;
int n, m, Parent[MAX];
ll distance[MAX];
int Find(int idx)
{
    if(Parent[idx] < 0)
    {
        return idx;
    }
    int p = Find(Parent[idx]);
    distance[idx] += distance[Parent[idx]];
    return Parent[idx] = p;
}
void Union(int x, int y, int w)
{
    int root_x = Find(x);
    int root_y = Find(y);
    if(root_x == root_y)
    {
        return ;
    }
    if(Parent[root_x] > Parent[root_y])
    {
        distance[root_x] = distance[y] - distance[x] - w;
        Parent[root_y] += Parent[root_x];
        Parent[root_x] = root_y;
    }
    else
    {
        distance[root_y] = distance[x] - distance[y] + w;
        Parent[root_x] += Parent[root_y];
        Parent[root_y] = root_x;
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    while(1)
    {
        std::cin >> n >> m;
        if(n == 0 && m == 0)
        {
            break;
        }
        std::memset(Parent, -1, sizeof(Parent));
        std::memset(distance, 0, sizeof(distance));
        while(m--)
        {
            char op;
            int a, b, w;
            std::cin >> op >> a >> b;
            if(op == '!')
            {
                std::cin >> w;
                Union(a, b, w);
                
            }
            else if(Find(a) != Find(b))
            {
                std::cout << "UNKNOWN\n";
            }
            else
            {
                std::cout << distance[b] - distance[a] << '\n';
            }
        }
    }
    return 0;
}