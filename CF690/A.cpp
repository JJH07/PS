#include <iostream>
int list[300];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n;
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            std::cin >> list[i];
        }
        int l = 0, r = n - 1;
        while(l <= r)
        {
            std::cout << list[l++] << ' ';
            if(l > r)
            {
                break;
            }
            else
            {
                std::cout << list[r--] << ' ';
            }
        }
        std::cout << '\n';
    }
    return 0;
}