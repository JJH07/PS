#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#define MAX 10
int n, k, table[4];
std::set<std::string> list;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> cards;
    std::cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        cards.push_back(number);
    }
    std:sort(cards.begin(), cards.end());
    do
    {
        std::string number;
        for(int i = 0; i < k; i++)
        {
            number += std::to_string(cards[i]);
        }
        list.insert(number);
    }
    while(std::next_permutation(cards.begin(), cards.end()));
    std::cout << list.size() << '\n';
    return 0;
}