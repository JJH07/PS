// Copyright © 2019 진준호. All rights reserved.

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long targetSum;
    int minimumLength;
    std::cin >> targetSum >> minimumLength;

    for(int length = minimumLength; length <= 100; length++)
    {
        // targetSum = length * firstTerm + length * (length - 1) / 2.
        const long long remainingSum = targetSum - 1LL * length * (length - 1) / 2;
        if(remainingSum < 0)
        {
            break;
        }
        if(remainingSum % length != 0)
        {
            continue;
        }
        const long long firstTerm = remainingSum / length;
        for(int offset = 0; offset < length; offset++)
        {
            if(offset > 0)
            {
                std::cout << ' ';
            }
            std::cout << firstTerm + offset;
        }
        std::cout << '\n';
        return 0;
    }
    std::cout << "-1\n";
    return 0;
}
