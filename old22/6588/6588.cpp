#include <bits/stdc++.h>
#define MAX 1000000

int Prime[MAX + 1];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(Prime, Prime + MAX, 1);

    for(int i = 2; i <= MAX / 2; i++)
    {
        if(!Prime[i])
        {
            continue;
        }
        for(int j = 2; i * j < MAX; j++)
        {
            Prime[i * j] = 0;
        }
    }
    
    int number;
    while(std::cin >> number)
    {
        if(number == 0)
        {
            break;
        }

        bool Found = false;
        for(int i = 2; i <= number / 2; i++)
        {
            if(Prime[i] && Prime[number - i])
            {
                std::cout << number << " = " << i << " + " << number - i << '\n';
                Found = true;
                break;
            }
        }
        if(!Found)
        {
            std::cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}