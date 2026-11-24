#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for(int &number : numbers)
    {
        std::cin >> number;
    }
    std::sort(numbers.begin(), numbers.end());

    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        bool found = false;
        for(int j = 0; j < n && !found; j++)
        {
            if(i == j)
            {
                continue;
            }
            const int needed = numbers[i] - numbers[j];
            const auto [first, last] = std::equal_range(numbers.begin(), numbers.end(), needed);
            const int available = static_cast<int>(last - first)
                - (numbers[i] == needed) - (numbers[j] == needed);
            found = available > 0;
        }
        answer += found;
    }
    std::cout << answer << '\n';
    return 0;
}
