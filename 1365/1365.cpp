#include <iostream>
#include <vector>
#define MAX 100001
int n, link[MAX];
std::vector<int> ans;
int bsearch(int l, int r, int v)
{
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(ans[mid] < v)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    ans.push_back(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int link;
        std::cin >> link;
        if(ans.back() < link)
        {
            ans.push_back(link);
        }
        else
        {
            int idx = bsearch(0, (int)ans.size() - 1, link);
            ans[idx] = link;
        }
    }
    std::cout << n - (ans.size() - 1) << '\n';
    return 0;
}