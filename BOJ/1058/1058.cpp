#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int personCount;
    std::cin >> personCount;
    std::string friendships[50];
    for(int person = 0; person < personCount; person++)
    {
        std::cin >> friendships[person];
    }

    int maximumTwoFriends = 0;
    for(int person = 0; person < personCount; person++)
    {
        int twoFriendCount = 0;
        for(int other = 0; other < personCount; other++)
        {
            if(person == other)
            {
                continue;
            }
            bool isTwoFriend = friendships[person][other] == 'Y';
            for(int intermediary = 0; !isTwoFriend && intermediary < personCount; intermediary++)
            {
                isTwoFriend = friendships[person][intermediary] == 'Y' &&
                              friendships[intermediary][other] == 'Y';
            }
            if(isTwoFriend)
            {
                twoFriendCount++;
            }
        }
        maximumTwoFriends = std::max(maximumTwoFriends, twoFriendCount);
    }
    std::cout << maximumTwoFriends << '\n';
    return 0;
}
