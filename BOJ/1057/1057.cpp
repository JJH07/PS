// Copyright © 2019 진준호. All rights reserved.

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int participantCount, firstPlayer, secondPlayer;
    std::cin >> participantCount >> firstPlayer >> secondPlayer;
    int meetingRound = 0;
    while(firstPlayer != secondPlayer)
    {
        firstPlayer = (firstPlayer + 1) / 2;
        secondPlayer = (secondPlayer + 1) / 2;
        meetingRound++;
    }
    std::cout << meetingRound << '\n';
    return 0;
}
