#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

struct p{
    int a, b, c;
};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> list(3);
    bool FLAG = false;
    std::queue<p> q;
    bool visited[501][501];
    
    std::memset(visited, 0, sizeof(visited));
    
    std::cin >> list[0] >> list[1] >> list[2];
    std::sort(list.begin(), list.end());
    
    q.push({list[0], list[1], list[2]});
    visited[list[0]][list[1]] = 1;

    while(!q.empty())
    {
        auto [a, b, c] = q.front();
        q.pop();
        if(a == b && a == c)
        {
            FLAG = true;
            break;
        }
        list[0] = a + a;
        list[1] = b;
        list[2] = c - a;
        std::sort(list.begin(), list.end());
        if(!visited[list[0]][list[1]])
        {
            visited[list[0]][list[1]] = 1;
            q.push({list[0], list[1], list[2]});
        }
        list[0] = a;
        list[1] = b + b;
        list[2] = c - b;
        std::sort(list.begin(), list.end());
        if(!visited[list[0]][list[1]])
        {
            visited[list[0]][list[1]] = 1;
            q.push({list[0], list[1], list[2]});
        }
    }
    std::cout << FLAG << '\n';
    return 0;
}