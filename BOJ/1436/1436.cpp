#include <iostream>
#include <string>
#include <algorithm>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, cnt = 0;
    std::cin >> n;
    for(int i = 666; i <= 10000000; i++)
    {
        std::string t = std::to_string(i);
        if(t.find("666") != -1)
        {
            ++cnt;
        }
        if(cnt == n)
        {
            std::cout << i << '\n';
            break;
        }
    }
    return 0;
}
