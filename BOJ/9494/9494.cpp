#include <iostream>
#include <string>
std::string flush;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    while(1)
    {
        int n, len, ans = 0;
        std::string str;
        std::cin >> n;
        if(n == 0)
        {
            break;
        }
        std::getline(std::cin, flush);
        while(n--)
        {
            std::getline(std::cin, str);
            len = str.length();
            int idx = ans;
            while(idx < len)
            {
                if(str[idx] == ' ')
                {
                    break;
                }
                ++idx;
            }
            ans = idx;
        }
        std::cout << ans + 1 << '\n';
    }
    return 0;
}