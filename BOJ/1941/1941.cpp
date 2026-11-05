#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
typedef std::pair<int, int> pii;
std::vector<int> pos;
std::string map[5];
bool visited[5][5];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int ans = 0;
    for(int i = 0; i < 18; i++)
    {
        pos.push_back(0);
    }
    for(int i = 0; i < 7; i++)
    {
        pos.push_back(1);
    }
    for(int i = 0; i < 5; i++)
    {
        std::cin >> map[i];
    }
    do
    {
        int S = 0, Y = 0, cnt = 0;
        pii front;
        std::queue<pii> q;
        std::memset(visited, 0, sizeof(visited));
        for(int i = 0; i < 25; i++)
        {
            if(pos[i])
            {
                front.first = i / 5;
                front.second = i % 5;
                visited[front.first][front.second] = true;
                map[front.first][front.second] == 'S' ? S++ : Y++;
            }
        }
        if(S < 4)
        {
            continue;
        }
        cnt++;
        q.push(front);
        visited[front.first][front.second] = false;
        while(!q.empty())
        {
            front = q.front();
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = dx[i] + front.first;
                int ny = dy[i] + front.second;
                if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || !visited[nx][ny])
                {
                    continue;
                }
                cnt++;
                q.push({nx, ny});
                visited[nx][ny] = false;
            }
        }
        if(cnt == 7)
        {
            ans++;
        }
    }
    while(std::next_permutation(pos.begin(), pos.end()));
    std::cout << ans << '\n';
    return 0;
}