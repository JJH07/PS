#include <bits/stdc++.h>
int n, A[50], B[50];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> A[i];
    }
    for(int i = 0; i < n; i++)
    {
        std::cin >> B[i];
    }
    std::sort(A, A + n);
    std::sort(B, B + n);

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += A[i] * B[n  - i - 1];
    }
    std::cout << ans << '\n';
    return 0;
}