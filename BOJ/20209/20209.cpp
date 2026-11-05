#include <iostream>
#include <vector>
#include <set>
#include <queue>

int n, k;
std::vector<int> Cube;
std::vector<int> Switch[9];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k;
    Cube.resize(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> Cube[i];
    }
    for(int i = 1; i <= k; i++)
    {
        int c;
        std::cin >> c;
        Switch[i].resize(c);
        for(int j = 0; j < c; j++)
        {
            std::cin >> Switch[i][j];
        }
    }

    std::queue<std::pair<int, std::vector<int>>> q;
    std::set<std::vector<int>> visited;

    q.push({0, Cube});
    visited.insert(Cube);
    while(!q.empty())
    {
        auto [p, now] = q.front();
        q.pop();
        bool FLAG = true;
        for(int i = 1; i < n; i++)
        {
            if(now[i] != now[0])
            {
                FLAG = false;
                break;
            }
        }
        if(FLAG)
        {
            std::cout << p << '\n';
            return 0;
        }
        for(int i = 1; i <= k; i++)
        {
            std::vector<int> next = now;
            for(auto pos : Switch[i])
            {
                next[pos - 1] = (next[pos - 1] + i) % 5;
            }
            if(visited.find(next) == visited.end())
            {
                q.push({p + 1, next});
                visited.insert(next);
            }
        }
    }
    std::cout << "-1\n";
    return 0;
}