#include <iostream>
;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n, one = 0, two = 0;
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            int t;
            std::cin >> t;
            if(t == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }
        if(one % 2)
        {
            std::cout << "NO\n";
        }
        else if(two % 2)
        {
            std::cout << (one >= 2 ? "YES\n" : "NO\n");            
        }
        else
        {
            std::cout << "YES\n";
        }
    }
    return 0;
}