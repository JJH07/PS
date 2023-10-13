#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 202
#define INF 1e9
int Source = 0, Sink = MAX - 1;
int Flow[MAX][MAX], Capacity[MAX][MAX], Cost[MAX][MAX];
std::vector<int> Edges[MAX];
void MCMF()
{
    int Price = 0, Count = 0;
    while(1)
    {
        std::vector<int> Before(MAX, -1), in_queue(MAX, 0), distance(MAX, INF);
        std::queue<int> q;

        distance[Source] = 0;
        in_queue[Source] = 1;
        q.push(Source);
        while(!q.empty())
        {
            int now = q.front();
            in_queue[now] = 0;
            q.pop();

            for(int next : Edges[now])
            {
                int ndist = distance[now] + Cost[now][next];
                if(Capacity[now][next] > Flow[now][next] && distance[next] > ndist)
                {
                    Before[next] = now;
                    distance[next] = ndist;
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
            Price += flow * Cost[Before[n]][n];
            Flow[Before[n]][n] += flow;
            Flow[n][Before[n]] -= flow;
        }
        Count += flow;
    }
    std::cout << Count << '\n' << Price << '\n';
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
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
            std::cin >> Capacity[Store][Customer + 100];
            Edges[Store].push_back(Customer + 100);
            Edges[Customer + 100].push_back(Store);
        }
    }
    for(int Store = 1; Store <= m; Store++)
    {
        for(int Customer = 1; Customer <= n; Customer++)
        {
            int Price;
            std::cin >> Price;
            Cost[Store][Customer + 100] = Price;
            Cost[Customer + 100][Store] = -Price;
        }
    }
    MCMF();
    return 0;
}