#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 50
#define INF 1000000
typedef std::pair<int, int> pii;
pii PostOffice;
int n, height[MAX][MAX], House;
std::string map[MAX];
std::vector<int> hList;
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1}, dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool bfs(int L, int R)
{
    int delivered = 0;
    std::queue<pii> q;
    bool visited[MAX][MAX];
    std::memset(visited, 0, sizeof(visited));
    if(L <= height[PostOffice.first][PostOffice.second] && height[PostOffice.first][PostOffice.second] <= R)
    {
        q.push(PostOffice);
        visited[PostOffice.first][PostOffice.second] = true;
    }
    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if(map[x][y] == 'K')
        {
            ++delivered;
        }
        if(delivered == House)
        {
            return true;
        }
        for(int i = 0; i < 8; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny])
            {
                continue;
            }
            if(L <= height[nx][ny] && height[nx][ny] <= R)
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> map[i];
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] == 'P')
            {
                PostOffice = {i, j};
            }
            else if(map[i][j] == 'K')
            {
                ++House;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> height[i][j];
            hList.push_back(height[i][j]);
        }
    }
    std::sort(hList.begin(), hList.end());
    hList.erase(std::unique(hList.begin(), hList.end()), hList.end());
    int l = 0, r = 0, ans = INF;
    while(l <= r)
    {
        if(r == hList.size())
        {
            break;
        }
        if(bfs(hList[l], hList[r]))
        {
            ans = std::min(ans, hList[r] - hList[l]);
            ++l;
        }
        else
        {
            ++r;
        }
    }
    std::cout << ans << '\n';
    return 0;
}