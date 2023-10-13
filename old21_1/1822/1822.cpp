#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b;
    std::vector<int> ans, A, B;
    std::cin >> a >> b;
    for(int i = 0; i < a; i++)
    {
        int t;
        std::cin >> t;
        A.push_back(t);
    }
    for(int i = 0; i < b; i++)
    {
        int t;
        std::cin >> t;
        B.push_back(t);
    }
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    int ai = 0, bi = 0;
    while(ai < a)
    {
        if(bi >= b || A[ai] < B[bi])
        {
            ans.push_back(A[ai++]);
        }
        else if(A[ai] == B[bi])
        {
            ai++;
            bi++;
        }
        else
        {
            bi++;
        }
    }
    std::cout << ans.size() << '\n';
    for(auto x : ans)
    {
        std::cout << x << ' ';
    }
    return 0;
}