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
    while(1)
    {
        std::cout << q.front() << ' ';
        q.pop();
        if(q.empty())
        {
            break;
        }
        q.push(q.front());
        q.pop();
    }
    return 0;
}