#include <iostream>
#define MAX 100001
int pos[MAX], tree[MAX * 4];
int init(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = 1;
    }
    return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}
int sum(int node, int start, int end, int left, int right)
{
    if(left > right)
    {
        return 0;
    }
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(int node, int start, int end, int idx)
{
    if(end < idx || idx < start)
    {
        return ;
    }
    tree[node]--;
    if(start != end)
    {
        update(node * 2, start, (start + end) / 2, idx);
        update(node * 2 + 1, (start + end) / 2 + 1, end, idx);
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int number;
        std::cin >> number;
        pos[number] = i;
    }
    init(1, 1, n);
    int l = 1, r = n, step = 1;
    while(l <= r)
    {
        int now = (step % 2) ? pos[l++] : pos[r--];
        if(step % 2)
        {
            std::cout << sum(1, 1, n, 1, now - 1) << '\n';
        }
        else
        {
            std::cout << sum(1, 1, n, now + 1, n) << '\n';
        }
        update(1, 1, n, now);
        step++;
    }
    return 0;
}