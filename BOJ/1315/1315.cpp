// Copyright © 2020 진준호. All rights reserved.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

struct Quest
{
    int strReq;
    int intReq;
    int reward;
};
int n, dp[1001][1001];
std::vector<Quest> quests;
int maxQuests(int str, int intel)
{
    int &result = dp[str][intel];
    if(result != -1)
    {
        return result;
    }
    result = 0;
    int points = 0;
    for(const Quest &quest : quests)
    {
        if(str >= quest.strReq || intel >= quest.intReq)
        {
            points += quest.reward;
            result++;
        }
    }
    const int remaining = points - str - intel + 2;
    for(const Quest &quest : quests)
    {
        if(quest.strReq > str && remaining >= quest.strReq - str)
        {
            result = std::max(result, maxQuests(quest.strReq, intel));
        }
        if(quest.intReq > intel && remaining >= quest.intReq - intel)
        {
            result = std::max(result, maxQuests(str, quest.intReq));
        }
    }
    return result;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::memset(dp, -1, sizeof(dp));

    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        Quest quest;
        std::cin >> quest.strReq >> quest.intReq >> quest.reward;
        quests.push_back(quest);
    }

    std::cout << maxQuests(1, 1) << '\n';
    return 0;
}
