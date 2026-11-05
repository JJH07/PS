#include <iostream>
#include <vector>
#include <cstring>

int parent[10001];
int get_lv(int idx)
{
    int lv = 0;
    while(parent[idx] > 0)
    {
        lv++;
        idx = parent[idx];
    }
    return lv;
}
int NCA(int x, int y)
{
    int x_lv = get_lv(x);
    int y_lv = get_lv(y);
    if(x_lv > y_lv)
    {
        std::swap(x_lv, y_lv);
        std::swap(x, y);
    }
    while(1)
    {
        if(x == y)
        {
            break;
        }
        if(x_lv == y_lv)
        {
            x_lv--;
            y_lv--;
            x = parent[x];
            y = parent[y];
        }
        else
        {
            y_lv--;
            y = parent[y];
        }
    }
    return x;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while(T--)
    {
        int n;
        std::cin >> n;
        std::memset(parent, 0, sizeof(parent));
        for(int i = 0; i < n - 1; i++)
        {
            int a, b;
            std::cin >> a >> b;
            parent[b] = a;
        }
        int x, y;
        std::cin >> x >> y;
        std::cout << NCA(x, y) << '\n';
    }

    return 0;
}