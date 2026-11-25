// Copyright © 2020 진준호. All rights reserved.

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    unsigned long long sizes[1000], clusterSize, totalSize = 0;

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> sizes[i];
    }
    std::cin >> clusterSize;

    for(int i = 0; i < n; i++)
    {
        const unsigned long long clusters = sizes[i] / clusterSize
            + (sizes[i] % clusterSize != 0);
        totalSize += clusters * clusterSize;
    }
    std::cout << totalSize << '\n';

    return 0;
}
