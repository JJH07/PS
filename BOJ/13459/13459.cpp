#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#define MAX 10
typedef std::pair<int, int> pii;
struct node{
    pii red, blue;
    int step;
};
int n, m;
std::string map[MAX];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
pii Move(pii now, int way, pii block)
{
    pii next = now;
    while(1)
    {
        int nx = dx[way] + next.first;
        int ny = dy[way] + next.second;
        if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == '#')
        {
            break;
        }
        if(block.first == nx && block.second == ny)
        {
            break;
        }
        if(map[nx][ny] == 'O')
        {
            return {-1, -1};
        }
        next = {nx, ny};
    }
    return next;
}
bool simulate()
{
    bool visited[MAX][MAX][MAX][MAX];
    std::queue<node> q;
    node front;

    std::memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == 'R')
            {
                map[i][j] = '.';
                front.red = {i, j};
            }
            else if(map[i][j] == 'B')
            {
                map[i][j] = '.';
                front.blue = {i, j};
            }
        }
    }
    front.step = 0;
    visited[front.red.first][front.red.second][front.blue.first][front.blue.second] = true;
    q.push(front);
    while(!q.empty())
    {
        auto [Red, Blue, Step] = q.front();
        q.pop();
        if(Step > 10)
        {
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            pii nRed, nBlue;
            if(Red.first * dx[i] < Blue.first * dx[i] || Red.second * dy[i] < Blue.second * dy[i])
            {
                nBlue = Move(Blue, i, Red);
                nRed = Move(Red, i , nBlue);
            }
            else
            {
                nRed = Move(Red, i, Blue);
                nBlue = Move(Blue, i, nRed);
            }
            if(nBlue.first == -1)
            {
                continue;
            }
            if(nRed.first == -1)
            {
                return Step <= 9;
            }
            if(visited[nRed.first][nRed.second][nBlue.first][nBlue.second])
            {
                continue;
            }
            visited[nRed.first][nRed.second][nBlue.first][nBlue.second] = true;
            q.push({nRed, nBlue, Step + 1});
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        std::cin >> map[i];
    }
    std::cout << simulate() << '\n';
    return 0;
}