#include <iostream>
#define MAX 100001
int n, k, tree[MAX * 4];

int init(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = 1;
    }
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}
int find(int node, int start, int end, int kth)
{
    if(start == end)
    {
        return start;
    }
    int mid = (start + end) / 2;
    int left = tree[node * 2];
    int right = tree[node * 2 + 1];
    return left < kth ? find(node * 2 + 1, mid + 1, end, kth - left) : find(node * 2, start, mid, kth);
}
void update(int node, int start, int end, int idx)
{
    if(idx < start || end < idx)
    {
        return ;
    }
    tree[node]--;
    if(start != end)
    {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx);
        update(node * 2 + 1, mid  + 1, end, idx);
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k;
    init(1, 1, n);

    int kth = k;

    std::cout << '<';
    while(1)
    {
        while(kth > tree[1])
        {
            kth -= tree[1];
        }
        int num = find(1, 1, n, kth);
        std::cout << num;
        update(1, 1, n, num);
        if(tree[1] == 0)
        {
            break;
        }
        kth += k - 1;
        std::cout << ", ";
    }
    std::cout << ">\n";
    return 0;
}