#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
struct Person{
    int h, w, idx;
    bool operator<(const Person &rhs) const{
        if(h == rhs.h)
        {
            return w < rhs.w;
        }
        return h < rhs.h;
    };
};
const int MAX = 2e5;
int n, ans[MAX + 1];
std::vector<Person> P;
std::vector<int> list;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--)
    {
        std::memset(ans, -1, sizeof(ans));
        std::cin >> n;
        for(int i = 1; i <= n; i++)
        {
            int h, w;
            std::cin >> h >> w;
            if(h > w)
            {
                std::swap(h, w);
            }
            P.push_back({h, w, i});
        }
        std::sort(P.begin(), P.end());
        Person Min = P[0], Keep = P[0];
        for(int i = 1; i < n; i++)
        {
            if(P[i].h != P[i - 1].h)
            {
                if(Min.w > Keep.w)
                {
                    Min = Keep;
                }
                Keep = P[i];
            }
            if(Min.h < P[i].h && Min.w < P[i].w)
            {
                ans[P[i].idx] = Min.idx;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
        P.clear();
    }
    return 0;
}