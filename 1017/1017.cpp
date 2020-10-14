#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define MAX 1001

int n, A[MAX], B[MAX];
bool Prime[2001], check[MAX];
std::vector<int> adj[MAX];

bool dfs(int a)
{
    if(check[a])
    {
        return false;
    }
    check[a] = 1;
    for(auto &b : adj[a])
    {
        if(B[b] == 0 || dfs(B[b]))
        {
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    for(int i = 2; i <= 2000; i++)
    {
        if(!Prime[i])
        {
            for(int j = i + i; j <= 2000; j += i)
            {
                Prime[j] = true;
            }
        }
    }

    int first;
    std::vector<int> odd, even, ans;
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        if(i == 0)
        {
            first = number;
        }
        if(number & 1)
        {
            odd.push_back(number);
        }
        else
        {
            even.push_back(number);
        }
    }
    for(int i : odd)
    {
        for(int j : even)
        {
            if(!Prime[i + j])
            {
                adj[i].push_back(j);
            }
        }
    }
    while(1)
    {
        std::memset(A, 0, sizeof(A));
        std::memset(B, 0, sizeof(B));
        int Pair = 0;
        for(auto od : odd)
        {
            std::memset(check, 0, sizeof(check));
            if(dfs(od))
            {
                Pair++;
            }
        }
        if(Pair != n / 2)
        {
            break;
        }
        if(first & 1)
        {
            for(auto it = adj[first].begin(); it != adj[first].end(); it++)
            {
                if(*it == A[first])
                {
                    adj[first].erase(it);
                    break;
                }
            }
            ans.push_back(A[first]);
        }
        else
        {
            for(auto it = adj[B[first]].begin(); it != adj[B[first]].end(); it++)
            {
                if(*it == first)
                {
                    adj[B[first]].erase(it);
                    break;
                }
            }
            ans.push_back(B[first]);
        }
    }
    if(ans.empty())
    {
        std::cout << "-1\n";
    }
    else
    {
        std::sort(ans.begin(), ans.end());
        for(auto x : ans)
        {
            std::cout << x << ' ';
        }
    }
    return 0;
}