#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
typedef std::pair<int, int> pii;
int n, m, indegree[MAX], distance[MAX];
bool visited[MAX];
std::vector<pii> link[MAX], link2[MAX];

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    while(m--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        link[a].push_back({b, c});
        link2[b].push_back({a, c});
        indegree[b]++;
    }
    std::queue<int> q;
    int s, e, cnt = 0;
    std::cin >> s >> e;
    q.push(s);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(auto [next, v] : link[now])
        {
            int ndist = distance[now] + v;
            if(ndist > distance[next])
            {
                distance[next] = ndist;
            }
            if(--indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
    q.push(e);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(auto [next, v] : link2[now])
        {
            if(distance[next] + v != distance[now])
            {
                continue;
            }
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
            cnt++;
        }
    }
    std::cout << distance[e] << '\n' << cnt <<  '\n';
}