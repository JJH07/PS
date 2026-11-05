#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
typedef std::pair<int, int> pii;
int map[9][9], row[9][10], col[9][10], block[9][10], list_sz;
std::vector<pii> list;
void init()
{
    for(int i = 0; i < 9; i++)
    {
        std::string t;
        std::cin >> t;
        for(int j = 0; j < 9; j++)
        {
            map[i][j] = t[j] - '0';
        }
    }
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(map[i][j] == 0)
            {
                list.push_back({i, j});
            }
            else
            {
                row[i][map[i][j]] = 1;
                col[j][map[i][j]] = 1;
                block[(i / 3) * 3 + (j / 3)][map[i][j]] = 1;
            }
        }
    }
    list_sz = (int)list.size();
}
bool dfs(int idx)
{
    if(idx == list_sz)
    {
        return true;
    }
    pii &now = list[idx];
    int block_idx = (now.first / 3) * 3 + (now.second / 3);
    for(int i = 1; i <= 9; i++)
    {
        if(!row[now.first][i] && !col[now.second][i] && !block[block_idx][i])
        {
            row[now.first][i] = 1;
            col[now.second][i] = 1;
            block[block_idx][i] = 1;
            if(dfs(idx + 1))
            {
                map[now.first][now.second] = i;
                return true;
            }
            row[now.first][i] = 0;
            col[now.second][i] = 0;
            block[block_idx][i] = 0;
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    init();
    dfs(0);
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            std::cout << map[i][j];
        }
        std::cout << '\n';
    }
    return 0;
}