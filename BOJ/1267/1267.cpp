// Copyright © 2020 진준호. All rights reserved.

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, yCost = 0, mCost = 0;
    std::cin >> n;
    while(n--)
    {
        int duration;
        std::cin >> duration;
        yCost += (duration / 30 + 1) * 10;
        mCost += (duration / 60 + 1) * 15;
    }
    if(yCost > mCost)
    {
        std::cout << "M " << mCost << '\n';
    }
    else if(yCost < mCost)
    {
        std::cout << "Y " << yCost << '\n';
    }
    else
    {
        std::cout << "Y M " << yCost << '\n';
    }
    return 0;
}
