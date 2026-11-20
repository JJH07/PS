// Copyright © 2019 진준호. All rights reserved.

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long gamesPlayed, gamesWon;
    std::cin >> gamesPlayed >> gamesWon;
    const long long winPercentage = 100 * gamesWon / gamesPlayed;
    if(winPercentage >= 99)
    {
        std::cout << "-1\n";
        return 0;
    }

    // 100 * (gamesWon + wins) >= (winPercentage + 1) * (gamesPlayed + wins).
    const long long deficit = (winPercentage + 1) * gamesPlayed - 100 * gamesWon;
    const long long gainPerWin = 99 - winPercentage;
    const long long additionalWins = (deficit + gainPerWin - 1) / gainPerWin;
    std::cout << additionalWins << '\n';
    return 0;
}
