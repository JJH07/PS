#include <iostream>
#include <set>
#include <string>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::set<int> s;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::string op;
        std::cin >> op;
        if(op == "all")
        {
            for(int i = 1; i <= 20; i++)
            {
                s.insert(i);
            }
        }
        else if(op == "empty")
        {
            s.clear();
        }
        else
        {
            int x;
            std::cin >> x;
            if(op == "add")
            {
                s.insert(x);
            }
            else if(op == "remove")
            {
                s.find(x) != s.end() ? s.erase(x) : 0;
            }
            else if(op == "check")
            {
                std::cout << s.count(x) << '\n';
            }
            else if(s.find(x) != s.end())
            {
                s.erase(x);
            }
            else
            {
                s.insert(x);
            }
        }
    }
    return 0;
}