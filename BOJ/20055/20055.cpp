#include <iostream>
#include <vector>
#include <cstring>

int n, k, up, down;
int durability[201];
bool used[201];
std::vector<int> robot;

bool simulate()
{
    up = (up == 1 ? n * 2 : up - 1);
    down = (down == 1 ? n * 2 : down - 1);
    for(auto it = robot.begin(); it != robot.end(); it++)
    {
        if(!used[*it])
        {
            break;
        }
        if(*it == down)
        {
            used[*it] = false;
            robot.erase(it);
            break;
        }
    }
    for(int i = 0; i < (int)robot.size(); i++)
    {
        int now = robot[i];
        int next = (now == n * 2 ? 1 : now + 1);
        if(durability[next] > 0 && !used[next])
        {
            used[next] = true;
            durability[next]--;
            robot[i] = next;

            used[now] = false;
        }
    }
    for(auto it = robot.begin(); it != robot.end(); it++)
    {
        if(!used[*it])
        {
            break;
        }
        if(*it == down)
        {
            used[*it] = false;
            robot.erase(it);
            break;
        }
    }
    if(durability[up] > 0 && !used[up])
    {
        used[up] = true;
        durability[up]--;
        robot.push_back(up);
    }
    int cnt = 0;
    for(int i = 1; i <= n * 2; i++)
    {
        if(durability[i] <= 0)
        {
            cnt++;
        }
    }
    return cnt >= k ? false : true;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k;
    for(int i = 1; i <= n * 2; i++)
    {
        std::cin >> durability[i];
    }
    up = 1, down = n;
    int step = 1;
    while(simulate())
    {
        step++;
    }
    std::cout << step << '\n';
    return 0;
}