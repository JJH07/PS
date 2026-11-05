#include <iostream>
#include <queue>
#include <string>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::queue<int> q;
    std::string op;
    std::cin >> n;
    while(n--)
    {
        std::cin >> op;
        if(op == "push")
        {
            int x;
            std::cin >> x;
            q.push(x);
        }
        else if(op == "size")
        {
            std::cout << q.size() << '\n';
        }
        else if(op == "empty")
        {
            std::cout << q.empty() << '\n';
        }
        else if(q.empty())
        {
            std::cout << "-1\n";
        }
        else if(op == "pop")
        {
            std::cout << q.front() << '\n';
            q.pop();
        }
        else if(op == "front")
        {
            std::cout << q.front() << '\n';
        }
        else
        {
            std::cout << q.back() << '\n';
        }
    }
    return 0;
}