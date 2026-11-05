#include <iostream>
#include <set>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n;
        std::multiset<int> pq;

        std::cin >> n;
        while(n--)
        {
            char opc;
            int opd;
            std::cin >> opc >> opd;
            if(opc == 'I')
            {
                pq.insert(opd);
            }
            else if(pq.size() == 0)
            {
                continue;
            }
            else
            {
                auto it = opd == -1 ? pq.begin() : --pq.end();
                pq.erase(it);
            }
        }
        if(pq.empty())
        {
            std::cout << "EMPTY\n";
        }
        else
        {
            std::cout << *(--pq.end()) << ' ' << *pq.begin() << '\n';
        }
    }
    return 0;
}