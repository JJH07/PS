#include <bits/stdc++.h>
int len, A[81];
bool check(int idx)
{
    int half = idx / 2;
    for(int h = 1; h <= half; h++)
    {
        bool FLAG = false;
        for(int i = 0; i < h; i++)
        {
            if(A[idx - i] != A[idx - h - i])
            {
                FLAG = true;
                break;
            }
        }
        if(!FLAG)
        {
            return false; 
        }
    }
    return true;
}
bool solve(int idx)
{
    if(idx > len)
    {
        return true;
    }
    for(int i = 1; i <= 3; i++)
    {
        A[idx] = i;
        if(check(idx) && solve(idx + 1))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> len;
    solve(1);
    for(int i = 1; i <= len; i++)
    {
        std::cout << A[i];
    }
    std::cout << '\n';
    return 0;
}