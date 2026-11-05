#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 302
int n, k, d, Source = 0, Sink = MAX - 1;
int Capacity[MAX][MAX], Flow[MAX][MAX];
std::vector<int> edges[MAX];
void Linking(int u, int v, int Cap)
{
    Capacity[u][v] = Cap;
    edges[u].push_back(v);
    edges[v].push_back(u);
}
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

    std::cin >> n >> k >> d;
    for(int i = 1; i <= d; i++)
    {   
        int Cap;
        std::cin >> Cap;
        Linking(i + 200, Sink, Cap);
    }
    for(int i = 1; i <= n; i++)
    {
        Linking(Source, i, k);
        int c;
        std::cin >> c;
        while(c--)
        {
            int Food;
            std::cin >> Food;
            Linking(i, Food + 200, 1);
        }
    }
    std::cout << Max_Flow() << '\n';
    return 0;
}