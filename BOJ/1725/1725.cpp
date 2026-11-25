#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
constexpr int MAX = 100000;

int n, heights[MAX], tree[MAX * 4];
int buildTree(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = start;
    }
    int left = buildTree(node * 2, start, (start + end) / 2);
    int right = buildTree(node * 2 + 1, (start + end) / 2 + 1, end);
    return tree[node] = heights[left] > heights[right] ? right : left;
}
int minIndex(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return -1;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    int leftIndex = minIndex(node * 2, start, (start + end) / 2, left, right);
    int rightIndex = minIndex(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    if(leftIndex == -1)
    {
        return rightIndex;
    }
    if(rightIndex == -1)
    {
        return leftIndex;
    }
    return heights[leftIndex] > heights[rightIndex] ? rightIndex : leftIndex;
}
int maxArea()
{
    int best = 0;
    std::vector<std::pair<int, int>> ranges{{0, n - 1}};
    while(!ranges.empty())
    {
        auto [left, right] = ranges.back();
        ranges.pop_back();
        int index = minIndex(1, 0, n - 1, left, right);
        best = std::max(best, heights[index] * (right - left + 1));
        if(index < right)
        {
            ranges.push_back({index + 1, right});
        }
        if(left < index)
        {
            ranges.push_back({left, index - 1});
        }
    }
    return best;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> heights[i];
    }
    buildTree(1, 0, n - 1);
    std::cout << maxArea() << '\n';
}
