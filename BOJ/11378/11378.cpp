#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1001
int n, m, k, working[MAX];
std::vector<int> worker[MAX];
bool check[MAX];
bool dfs(int w)
{
    for(int job : worker[w])
    {
        if(check[job])
        {
            continue;
        }
        check[job] = 1;
        if(working[job] == 0 || dfs(working[job]))
        {
            working[job] = w;
            return true;
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        int c;
        std::cin >> c;
        while(c--)
        {
            int w;
            std::cin >> w;
            worker[i].push_back(w);
        }
    }
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        std::memset(check, 0, sizeof(check));
        count += dfs(i);
    }
    for(int i = 1; i <= n; i++)
    {
        while(k)
        {
            std::memset(check, 0, sizeof(check));
            if(dfs(i))
            {
                count++;
                k--;
            }
            else
            {
                break;
            }
        }
    }
    std::cout << count << '\n';
    return 0;
}