#include <iostream>
#include <vector>
#define MAX 1001
int n, X[MAX], Y[MAX];
inline int get_dist(int i, int j)
{
    return (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]); 
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int Min = 1e9, ans = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> X[i] >> Y[i];
    }
    for(int i = 0; i < n; i++)
    {
        int Max = -1, idx = 0;
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                continue;
            }
            int dist = get_dist(i, j);
            if(dist > Max)
            {
                Max = dist;
                idx = i;
            }
        }
        if(Min > Max)
        {
            Min = Max;
            ans = idx;
        }
    }
    std::cout << X[ans] << ' ' << Y[ans] << '\n';
    return 0;
}