#include <iostream>
#include <string>
int n, m, remember, wordlist[10001];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;

    for(int i = 0; i < 26; i++)
    {
        remember |= (1 << i);
    }
    for(int i = 0; i < n; i++)
    {
        std::string word;
        std::cin >> word;
        for(char &c : word)
        {
            wordlist[i] |= (1 << (int)(c - 'a'));
        }
    }
    for(int i = 0; i < m; i++)
    {
        int opc, ans = 0;
        char opd;
        std::cin >> opc >> opd;
        remember ^= (1 << (int)(opd - 'a'));
        for (int j = 0; j < n; j++)
        {
            if((wordlist[j] & remember) == wordlist[j])
            {
                ans++;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}