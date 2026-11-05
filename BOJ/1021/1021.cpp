#include <iostream>
#include <queue>
int Find(std::deque<int> &dq, int number)
{
    int sz = (int)dq.size();
    int pos;
    for(pos = 0; pos < sz; pos++)
    {
        if(dq[pos] == number)
        {
            break;
        }
    }
    int ret = std::min(pos, sz - pos);
    for(int i = 0; i < ret; i++)
    {
        if(pos < sz - pos)
        {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        else
        {
            dq.push_front(dq.back());
            dq.pop_back();
        }
    }
    dq.pop_front();
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, ans = 0;
    std::deque<int> deq;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        deq.push_back(i);
    }
    while(m--)
    {
        int number;
        std::cin >> number;
        ans += Find(deq, number);
    }   
    std::cout << ans << '\n';
    return 0;
}