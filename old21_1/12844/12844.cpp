#include <iostream>
#include <cstring>
#define MAX 500001

int list[MAX], tree[MAX * 4], lazy[MAX * 4];
void propagate(int node, int start, int end)
{
    if(lazy[node] > 0)
    {
        if(start != end)
        {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        if((end - start + 1) % 2)
        {
            tree[node] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}
int init(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = list[start];
    }
    return tree[node] = init(node * 2, start, (start + end) / 2) ^ init(node * 2 + 1, (start + end) / 2 + 1, end);
}
int XOR(int node, int start, int end, int left, int right)
{
    propagate(node, start, end);
    if(right < start || end < left)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return XOR(node * 2, start, (start + end) / 2, left, right) ^ XOR(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(int node, int start, int end, int left, int right, int k)
{
    propagate(node, start, end);
    if(end < left || right < start)
    {
        return ;
    }
    if(left <= start && end <= right)
    {   
        lazy[node] = k;
        propagate(node, start, end);
        return ;
    }
    if(start != end)
    {
        update(node * 2, start, (start + end) / 2, left, right, k);
        update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, k);
        tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }
    init(1, 0, n - 1);
    std::cin >> m;
    while(m--)
    {
        int op, i, j;
        std::cin >> op >> i >> j;
        if(i > j)
        {
            std::swap(i, j);
        }
        if(op == 1)
        {
            int k;
            std::cin >> k;
            update(1, 0, n - 1, i, j, k);
        }
        else
        {
            std::cout << XOR(1, 0, n - 1, i, j) << '\n';
        }
        
    }
    return 0;
}