//
//  main.cpp
//  17394
//
//  Created by 진준호 on 2020/05/08.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
bool have_prime(int a, int b, int *table)
{
    for(int i = a; i <= b; i++)
    {
        if(table[i])
        {
            return true;
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T, prime_table[100001];
    std::fill(prime_table, prime_table + 100001, 1);
    
    for(int i = 2; i <= 100000; i++)
    {
        if(prime_table[i])
        {
            for(int j = 2; j <= 100000 / i; j++)
            {
                prime_table[i * j] = 0;
            }
        }
    }
    std::cin >> T;
    for(int i = 0; i < T; i++)
    {
        int N, A, B, visited[1000001], ans = -1;
        std::queue<std::pair<int, int>> q;
        std::memset(visited, 0, sizeof(visited));
        std::cin >> N >> A >> B;
        if(have_prime(A, B, prime_table))
        {
            q.push({N, 0});
            visited[N] = 1;
            while(!q.empty())
            {
                int number = q.front().first;
                int count = q.front().second;
                q.pop();
                if(number >= A && number <= B && prime_table[number])
                {
                    ans = count;
                    break;
                }
                int next[4];
                next[0] = number / 2;
                next[1] = number / 3;
                next[2] = number + 1;
                next[3] = number - 1;
                for(int i = 0; i < 4; i++)
                {
                    if(next[i] >= 1 && next[i] <= 1000000 && !visited[next[i]])
                    {
                        visited[next[i]] = 1;
                        q.push({next[i], count + 1});
                    }
                }
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}
