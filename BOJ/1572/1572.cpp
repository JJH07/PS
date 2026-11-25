#include <iostream>

using ll = long long;
constexpr int MAX_N = 250000;
constexpr int MAX_VALUE = 65535;
int values[MAX_N + 1];
ll tree[(MAX_VALUE + 1) * 4];

void update(int node, int start, int end, int index, int delta)
{
    tree[node] += delta;
    if(start == end)
    {
        return;
    }
    const int mid = (start + end) / 2;
    if(index <= mid)
    {
        update(node * 2, start, mid, index, delta);
    }
    else
    {
        update(node * 2 + 1, mid + 1, end, index, delta);
    }
}

int findKth(ll rank)
{
    int node = 1, left = 0, right = MAX_VALUE;
    while(left < right)
    {
        const int mid = (left + right) / 2;
        const ll leftCount = tree[node * 2];
        if(rank <= leftCount)
        {
            node *= 2;
            right = mid;
        }
        else
        {
            rank -= leftCount;
            node = node * 2 + 1;
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> values[i];
    }
    ll answer = 0;
    for(int i = 1; i <= n; i++)
    {
        update(1, 0, MAX_VALUE, values[i], 1);
        if(i >= k)
        {
            answer += findKth((k + 1) / 2);
            update(1, 0, MAX_VALUE, values[i - k + 1], -1);
        }
    }
    std::cout << answer << '\n';
    return 0;
}
