#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 200
int Source = 0, Sink = 25;
int Capacity[MAX][MAX], Flow[MAX][MAX];
std::vector<int> edges[MAX];
int Max_Flow()
{
    int ret = 0;
    while(1)
    {
        std::vector<int> Before(MAX, -1);
        std::queue<int> q;

        q.push(Source);
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            for(int next : edges[now])
            {
                if(Before[next] == -1 && Capacity[now][next] > Flow[now][next])
                {
                    q.push(next);
                    Before[next] = now;
                    if(next == Sink)
                    {
                        break;
                    }
                }
            }
        }
        if(Before[Sink] == -1)
        {
            break;
        }
        int flow = 1e9;
        for(int n = Sink; n != Source; n = Before[n])
        {
            flow = std::min(flow, Capacity[Before[n]][n] - Flow[Before[n]][n]);
        }
        for(int n = Sink; n != Source; n = Before[n])
        {
            Flow[Before[n]][n] += flow;
            Flow[n][Before[n]] -= flow;
        }
        ret += flow;
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char u, v;
        int Cap;
        std::cin >> u >> v >> Cap;
        u -= 'A';
        v -= 'A';
        Capacity[u][v] += Cap;
        Capacity[v][u] += Cap;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    std::cout << Max_Flow() << '\n';
    return 0;
}