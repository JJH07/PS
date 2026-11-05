#include <iostream>
#include <queue>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::queue<int> q;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while(q.size() > 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    std::cout << q.front() << '\n';
    return 0;
}