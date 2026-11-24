// Copyright © 2019 진준호. All rights reserved.

#include <iostream>
#include <map>
#include <string>

struct Color
{
    int digit;
    long long multiplier;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const std::map<std::string, Color> colors = {
        {"black", {0, 1}}, {"brown", {1, 10}}, {"red", {2, 100}},
        {"orange", {3, 1000}}, {"yellow", {4, 10000}}, {"green", {5, 100000}},
        {"blue", {6, 1000000}}, {"violet", {7, 10000000}},
        {"grey", {8, 100000000}}, {"white", {9, 1000000000}}
    };
    std::string first, second, third;
    std::cin >> first >> second >> third;

    const int digits = 10 * colors.at(first).digit + colors.at(second).digit;
    std::cout << digits * colors.at(third).multiplier << '\n';
    return 0;
}
