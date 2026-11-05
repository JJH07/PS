#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 202
#define INF 1e9
int Source = 0, Sink = MAX - 1;
int n, m;
int Capacity[MAX][MAX], Flow[MAX][MAX], Distance[MAX][MAX];
std::vector<int> Edges[MAX];
int MCMF()
{
    int ret = 0;
    while(1)
    {
        std::queue<int> q;
        std::vector<int> Before(MAX, -1), Dist(MAX, INF), in_queue(MAX, 0);
        
        Dist[Source] = 0;
        in_queue[Source] = 1;
        q.push(Source);
        
        while(!q.empty())
        {
            int now = q.front();
            in_queue[now] = 0;
            q.pop();

            for(int next : Edges[now])
            {
                int nDist = Dist[now] + Distance[now][next];
                if(Capacity[now][next] > Flow[now][next] && Dist[next] > nDist)
                {
                    Dist[next] = nDist;
                    Before[next] = now;
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
        for(int n = Sink; n != Source; n = Before[n])
        {
            ret += flow * Distance[Before[n]][n];
            Flow[Before[n]][n] += flow;
            Flow[n][Before[n]] -= flow;
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> Capacity[i + 100][Sink];
        Edges[i + 100].push_back(Sink);
        Edges[Sink].push_back(i + 100);

    }
    for(int i = 1; i <= m; i++)
    {
        std::cin >> Capacity[Source][i];
        Edges[Source].push_back(i);
        Edges[i].push_back(Source);
    }
    for(int Store = 1; Store <= m; Store++)
    {
        for(int Customer = 1; Customer <= n; Customer++)
        {
            int Price;
            std::cin >> Price;
            Distance[Store][Customer + 100] = Price;
            Distance[Customer + 100][Store] = -Price;
            Capacity[Store][Customer + 100] = INF;
            Edges[Store].push_back(Customer + 100);
            Edges[Customer + 100].push_back(Store);
        }
    }
    std::cout << MCMF() << '\n';
    return 0;
}