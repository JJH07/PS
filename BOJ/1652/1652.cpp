// Copyright © 2019 진준호. All rights reserved.

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::string> room(n);
    for(auto &line : room)
    {
        std::cin >> line;
    }

    int horizontal = 0, vertical = 0;
    for(int line = 0; line < n; line++)
    {
        int rowRun = 0, colRun = 0;
        for(int pos = 0; pos < n; pos++)
        {
            rowRun = room[line][pos] == '.' ? rowRun + 1 : 0;
            colRun = room[pos][line] == '.' ? colRun + 1 : 0;
            if(rowRun == 2)
            {
                horizontal++;
            }
            if(colRun == 2)
            {
                vertical++;
            }
        }
    }
    std::cout << horizontal << ' ' << vertical << '\n';
    return 0;
}
