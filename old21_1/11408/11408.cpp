#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 802
#define INF 1e9
int Source, Sink = MAX - 1;
int n, m, Capacity[MAX][MAX], Flow[MAX][MAX], Wage[MAX][MAX];
std::vector<int> Edges[MAX];
void MCMF()
{
    int Count = 0, Money = 0;
    while(1)
    {
        std::vector<int> Before(MAX, -1), in_queue(MAX, 0), Dist(MAX, INF);
        std::queue<int> q;

        Dist[Source] = 0;
        in_queue[Source] = 1;
        q.push(Source);
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            in_queue[now] = 0;
            for(int next : Edges[now])
            {
                int nDist = Dist[now] + Wage[now][next];
                if(Capacity[now][next] > Flow[now][next] && Dist[next] > nDist)
                {
                    Before[next] = now;
                    Dist[next] = nDist;
                    if(!in_queue[next])
                    {
                        in_queue[next] = 1;
                        q.push(next);
                    }
                }
            }
        }
        if(Before[Sink] == -1)
        {
            break;
        }
        int flow = INF;
        for(int n = Sink; n != Source; n = Before[n])
        {
            flow = std::min(flow, Capacity[Before[n]][n] - Flow[Before[n]][n]);
        }
        Count += flow;
        for(int n = Sink; n != Source; n = Before[n])
        {
            Money += flow * Wage[Before[n]][n];
            Flow[Before[n]][n] += flow;
            Flow[n][Before[n]] -= flow;
        }
    }
    std::cout << Count << '\n' << Money << '\n';
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        Capacity[Source][i] = 1;
        Edges[Source].push_back(i);
        Edges[i].push_back(Source);
    }
    for(int i = 1; i <= m; i++)
    {
        Capacity[i + 400][Sink] = 1;
        Edges[i + 400].push_back(Sink);
        Edges[Sink].push_back(i + 400);
    }
    for(int Worker = 1; Worker <= n; Worker++)
    {
        int c;
        std::cin >> c;
        while(c--)
        {
            int Job, Cost;
            std::cin >> Job >> Cost;
            Capacity[Worker][Job + 400] = 1;
            Edges[Worker].push_back(Job + 400);
            Edges[Job + 400].push_back(Worker);
            Wage[Worker][Job + 400] = Cost;
            Wage[Job + 400][Worker] = -Cost;
        }
    }
    MCMF();
    return 0;
}