#include <iostream>
#include <vector>

std::vector<int> list;
void dfs(int s, int e)
{
    int root = list[s];
    int mid = s++;
    while(mid <= e)
    {
        if(list[mid] > root)
        {
            break;
        }
        mid++;
    }
    if(s <= mid - 1)
    {
        dfs(s, mid - 1);
    }
    if(mid <= e)
    {
        dfs(mid, e);
    }
    std::cout << root << '\n';
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    while(std::cin >> t)
    {
        list.push_back(t);
    }
    dfs(0, list.size() - 1);
    return 0;
}