#include <bits/stdc++.h>
std::map<std::string, double> rating;
void init()
{
    rating.insert({"A+", 4.5});
    rating.insert({"A0", 4.0});
    rating.insert({"B+", 3.5});
    rating.insert({"B0", 3.0});
    rating.insert({"C+", 2.5});
    rating.insert({"C0", 2.0});
    rating.insert({"D+", 1.5});
    rating.insert({"D0", 1.0});
    rating.insert({"F", 0.0});
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    init();
    double s = 0.0, tot = 0.0;
    for(int i = 0; i < 20; i++)
    {
        std::string name, grade; double credit;
        std::cin >> name >> credit >> grade;
        if(!grade.compare("P"))
        {
            continue;
        }
        s += rating[grade] * credit;
        tot += credit;
    }
    double ans = (s == 0.0 ? 0.0 : s / tot);
    std::cout.precision(7);
    std::cout << std::fixed;
    std::cout << ans << '\n';

    return 0;
}