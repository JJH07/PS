#include <iostream>
#include <vector>

bool used[32001];
std::vector<int> pre[32001];
void Print(int idx)
{
    if(used[idx])
    {
        return ;
    }
    for(auto x : pre[idx])
    {
        Print(x);
    }
    used[idx] = 1;
    std::cout << idx << ' ';
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        pre[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        Print(i);
    }
    return 0;
}