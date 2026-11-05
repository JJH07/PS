#include <iostream>
#include <vector>
#define MAX 1000000
int n;
std::vector<int> ans;
int bsearch(int l, int r, int val)
{
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(ans[mid] < val)
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

    std::cin >> n;
    ans.push_back(0);
    for(int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        if(ans.back() < number)
        {
            ans.push_back(number);
        }
        else
        {
            int idx = bsearch(0, ans.size() - 1, number);
            ans[idx] = number;
        }
    }
    std::cout << ans.size() - 1 << '\n';
    return 0;
}