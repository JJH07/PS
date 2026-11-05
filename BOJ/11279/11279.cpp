#include <iostream>
#include <queue>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::priority_queue<int> pq;
    std::cin >> n;
    while(n--)
    {
        int number;
        std::cin >> number;
        if(number > 0)
        {
            pq.push(number);
        }
        else if(pq.empty())
        {
            std::cout << "0\n";
        }
        else
        {
            std::cout << pq.top() << '\n';
            pq.pop();
        }
    }
    return 0;
}