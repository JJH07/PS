#include <iostream>
#include <vector>
#include <cstring>

typedef std::vector<std::vector<int>> MATRIX;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    MATRIX matrix_t(2, std::vector<int>(2));
    std::cin >> t;
    while(t--)
    {
        int n, m;
        bool FLAG = false;
        std::cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                std::cin >> matrix_t[j][0] >> matrix_t[j][1];
            }
            if(!FLAG)
            {
                FLAG = (matrix_t[0][1] == matrix_t[1][0]);
            }
        }
        if(m % 2 > 0 || !FLAG)
        {
            std::cout << "NO\n";
        }
        else
        {
            std::cout << "YES\n";
        }
        
    }
    return 0;
}
