#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#define MAX 200001
struct query{
    int opcode, opd1, opd2;
};
int n, q, parent[MAX];
std::vector<query> queries;
int Find(int idx)
{
    if(parent[idx] < 0)
    {
        return idx;
    }
    return parent[idx] = Find(parent[idx]);
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b)
    {
        return ;
    }
    if(parent[a] > parent[b])
    {
        parent[b] += parent[a];
        parent[a] = b;
    }
    else
    {
        parent[a] += parent[b];
        parent[b] = a;
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(parent, -1, sizeof(parent));
    std::cin >> n >> q;
    for(int i = 1; i <= n - 1; i++)
    {
        int a;
        std::cin >> a;
        parent[i + 1] = a;
    }
    for(int i = 0; i < n + q - 1; i++)
    {
        int opc, opd1, opd2 = 0;
        std::cin >> opc >> opd1;
        if(opc ==  1)
        {
            std::cin  >> opd2;
        }
        else
        {
            opd2 = parent[opd1];
            parent[opd1] = -1;
        }
        queries.push_back({opc, opd1, opd2});
    }
    std::vector<std::string> answer;
    for(auto rb = queries.rbegin(); rb != queries.rend(); rb++)
    {
        if(rb->opcode == 0)
        {
            Union(rb->opd1, rb->opd2);
        }
        else
        {
            Find(rb->opd1) == Find(rb->opd2) ? answer.push_back("YES") : answer.push_back("NO");
        }
    }
    for(auto rb = answer.rbegin();  rb != answer.rend(); rb++)
    {
        std::cout << *rb << '\n';
    }
    return 0;
}