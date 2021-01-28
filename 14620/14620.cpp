#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 11
struct pos{
    int price, x, y;
    bool operator<(const pos &rhs) const{
        return price < rhs.price;
    }
};
int n, ans = 10000000, list_sz, table[3];
std::vector<pos> list;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void Init()
{
    int temp[MAX][MAX], Price[MAX][MAX];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> temp[i][j];
        }
    }
    for(int i = 1; i < n - 1; i++)
    {
        for(int j = 1; j < n - 1; j++)
        {
            Price[i][j] = temp[i][j];
            for(int di = 0; di < 4; di++)
            {
                Price[i][j] += temp[i + dx[di]][j +  dy[di]];
            }
            list.push_back({Price[i][j], i, j});
        }
    }
    std::sort(list.begin(), list.end());
}
void Permutation(int Sum, int idx, int Picked)
{
    if(Sum > ans)
    {
        return ;
    }
    if(Picked == 3)
    {
        ans = std::min(ans, Sum);
        return ;
    }
    for(int i = idx; i < list_sz; i++)
    {
        bool FLAG = true;
        pos &next = list[i];
        for(int j = 0; j < Picked; j++)
        {
            pos &now = list[table[j]];
            if(abs(next.x - now.x) + abs(next.y - now.y) < 3)
            {
                FLAG = false;
                break;
            }
        }
        if(FLAG)
        {
            table[Picked] = i;
            Permutation(Sum + next.price, i + 1, Picked + 1);
        }
    }
}
void Search()
{
    list_sz = (int)list.size();
    Permutation(0, 0, 0);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    Init();
    Search();
    std::cout << ans << '\n';
    return 0;
}