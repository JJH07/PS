#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

std::string key = "2020", r_key = "0202";
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        bool FLAG = false;
        int n;
        std::string str, r_str;
        std::cin >> n >> str;
        r_str = str;
        std::reverse(r_str.begin(), r_str.end());
        
        for(int s = 0; s <= 4; s++)
        {
            int e = 4 - s;
            std::string subkey = key.substr(0, s);
            std::string r_subkey = r_key.substr(0, e);
            if(str.find(subkey) == 0 && r_str.find(r_subkey) == 0)
            {
                FLAG = true;
                break;
            }
        }
        if(FLAG)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
        
    }
    return 0;
}