#include <bits/stdc++.h>
typedef std::pair<int, int> pii;

struct Crop{
    double r;
    int w;
    Crop(int X, int Y, int W) : r(sqrt(X * X + Y * Y)), w(W) {};
    bool operator<(const Crop &rhs) const{
        return r < rhs.r;
    }
};
int N, A;
std::vector<Crop> Crops;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(6);
    
    double ans = 0;
    std::cin >> N >> A;
    for(int i = 0; i < N; i++)
    {
        int x, y, w;
        std::cin >> x >> y >> w;
        Crops.push_back(Crop(x, y, w));
    }
    std::sort(Crops.begin(), Crops.end());
    int Wsum = 0;
    for(int i = 0; i < N; i++)
    {
        Wsum += Crops[i].w;
        double r = (1.0 * Wsum) / (2.0 * A);
        if(r < Crops[i].r)
        {
            continue;
        }
        if(r >= (i < N - 1 ? Crops[i + 1].r : 1e9))
        {
            continue;
        }
        double Profit = 0;
        for(int j = 0; j <= i; j++)
        {
            Profit += Crops[j].w * (r - Crops[j].r);
        }
        ans = std::max(ans, Profit - A * r * r);
    }
    std::cout << ans << '\n';
    return 0;
}


// c = r - ri
// sum(wi * (r - ri)) - (A * r * r)
// sum(wi) - 2 * A * r

