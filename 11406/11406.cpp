#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 202
int Source = 0, Sink = MAX - 1;
int Capacity[MAX][MAX], Flow[MAX][MAX];
std::vector<int> Edges[MAX];
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

            for(int next : Edges[now])
            {
                if(Before[next] == -1 && Capacity[now][next] > Flow[now][next])
                {
                    Before[next] = now;
                    q.push(next);
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
            int Stock;
            std::cin >> Stock;
            Capacity[Store][Customer + 100] = Stock;
            Edges[Store].push_back(Customer + 100);
            Edges[Customer + 100].push_back(Store);
        }
    }
    std::cout << Max_Flow() << '\n';
    return 0;
}