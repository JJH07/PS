#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX_V 500001
struct test{
    int t1;
    int t2;
    int t3;
    bool operator <(const test &rhs) const
    {
        if(t1 == rhs.t1)
        {
            if(t2 == rhs.t2)
            {
                return t3 < rhs.t3;
            }
            return t2 < rhs.t2;
        }
        return t1 < rhs.t1;
    }
};

int min(std::vector<int> &tree, int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return MAX_V;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return std::min(min(tree, node * 2, start, (start + end) / 2, left, right), min(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
void update(std::vector<int> &tree, int node, int start, int end, int idx, int val)
{
    if(idx < start || end < idx)
    {
        return ;
    }
    if(start <= idx && idx <= end)
    {
        tree[node] = std::min(tree[node], val);
    }
    if(start != end)
    {
        update(tree, node * 2, start, (start + end) / 2, idx, val);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, ans = 0;
    std::cin >> n;
    std::vector<test> Student(n + 1);
    std::vector<int> tree(1 << ((int)ceil(log2(n)) + 1), MAX_V);
    for(int i = 1; i <= n; i++)
    {
        int t;
        std::cin >> t;
        Student[t].t1 = i;
    }
    for(int i = 1; i <= n; i++)
    {
        int t;
        std::cin >> t;
        Student[t].t2 = i;
    }
    for(int i = 1; i <= n; i++)
    {
        int t;
        std::cin >> t;
        Student[t].t3 = i;
    }
    std::sort(Student.begin() + 1, Student.end());
    for(int i = 1; i <= n; i++)
    {
        int t2_rank = Student[i].t2;
        int t3_rank = Student[i].t3;
        if(t3_rank < min(tree, 1, 1, n, 1, t2_rank - 1))
        {
            ans++;
        }
        update(tree, 1, 1, n, t2_rank, t3_rank);
    }
    std::cout << ans << '\n';
    return 0;
}