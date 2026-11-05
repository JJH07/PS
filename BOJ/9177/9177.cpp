#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

std::string word[3];
int len[3];
bool visited[401][201][201];
struct node{
    int x, y, z;
};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::memset(visited, 0, sizeof(visited));
        std::queue<node> q;
        for(int j = 0; j < 3; j++)
        {
            std::cin >> word[j];
            len[j] = word[j].length();
        }
        q.push({0, 0, 0});
        visited[0][0][0] = 1;
        while(!q.empty())
        {
            auto [x, y, z] = q.front();
            q.pop();
            if(y < len[0] && word[2][x] == word[0][y] && !visited[x + 1][y + 1][z])
            {
                visited[x + 1][y + 1][z] = 1;
                q.push({x + 1, y + 1, z});
            }
            if(z < len[1] && word[2][x] == word[1][z] && !visited[x + 1][y][z + 1])
            {
                visited[x + 1][y][z + 1] = 1;
                q.push({x + 1, y, z + 1});
            }
        }
        std::cout << "Data set " << i << ": " << (visited[len[2]][len[0]][len[1]] ? "yes\n" : "no\n");
    }
    return 0;
}