#include <iostream>
#include <string>
#include <map>
int n, m;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, std::string> KeyChain;
    std::cin >> n >> m;
    while(n--)
    {
        std::string site, passwd;
        std::cin >> site >> passwd;
        KeyChain.insert({site, passwd});
    }
    while(m--)
    {
        std::string site;;
        std::cin >> site;
        std::cout << KeyChain[site] << '\n';
    }
    return 0;
}