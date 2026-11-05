#include <iostream>
#include <cstring>
#include <queue>
#define MAX 3000001

std::queue<int> q;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int L, ML, MK, MINE;
    bool ALIVE = true;
    std::cin >> L >> ML >> MK >> MINE;
    for(int i = 1; i <= L; i++)
    {
        int zombie, range;
        std::cin >> zombie;
        range = (i >= ML ? ML : i);
        while(!q.empty())
        {
            int front = q.front();
            if(front >= i)
            {
                break;
            }
            q.pop();
        }
        zombie -= (range - q.size()) * MK;
        if(zombie > 0)
        {
            MINE--;
            q.push(i + ML - 2);
        }
        if(MINE < 0)
        {
            ALIVE = false;
            break;
        }
    }
    std::cout << (ALIVE ? "YES\n" : "NO\n");
    return 0;
}
