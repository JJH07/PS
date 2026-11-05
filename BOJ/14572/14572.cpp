#include <iostream>
#include <vector>
#include <algorithm>
struct Student{
    int Skill;
    std::vector<int> know;
    bool operator <(const Student &rhs) const{
        return Skill < rhs.Skill;
    }
};
int n, k, d, table[31];
std::vector<Student> list;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int ans = 0;
    std::cin >> n >> k >> d;
    list.resize(n);
    for(int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m >> list[i].Skill;
        while(m--)
        {
            int algo;
            std::cin >> algo;
            list[i].know.push_back(algo);
        }
    }
    std::sort(list.begin(), list.end());
    int s = 0, e = 0;
    while(s < n)
    {
        if(e < n && list[e].Skill - list[s].Skill <= d)
        {
            int offset = 0, members = e - s + 1;
            for(auto x : list[e].know)
            {
                ++table[x];
            }
            for(int i = 1; i <= k; i++)
            {
                if(table[i] > 0)
                {
                    ++offset;
                }
                if(table[i] == members)
                {
                    --offset;
                }
            }
            ans = std::max(ans, offset * members);
            ++e;
        }
        else
        {
            for(auto x : list[s].know)
            {
                --table[x];
            }
            ++s;
        }
    }
    std::cout << ans << '\n';
    return 0;
}