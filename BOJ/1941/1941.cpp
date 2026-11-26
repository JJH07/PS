#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#include <string>

bool isConnected(const std::array<int, 7> &cells)
{
    bool selected[5][5];
    std::memset(selected, 0, sizeof(selected));
    for(int cell : cells)
    {
        selected[cell / 5][cell % 5] = true;
    }
    std::array<int, 7> queue;
    int head = 0, tail = 0;
    queue[tail++] = cells[0];
    selected[cells[0] / 5][cells[0] % 5] = false;
    constexpr int dr[4] = {0, 1, 0, -1};
    constexpr int dc[4] = {1, 0, -1, 0};
    while(head < tail)
    {
        int cell = queue[head++];
        for(int dir = 0; dir < 4; dir++)
        {
            int row = cell / 5 + dr[dir], col = cell % 5 + dc[dir];
            if(row < 0 || col < 0 || row >= 5 || col >= 5 || !selected[row][col])
            {
                continue;
            }
            selected[row][col] = false;
            queue[tail++] = row * 5 + col;
        }
    }
    return tail == 7;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<int, 25> chosen{};
    std::fill(chosen.end() - 7, chosen.end(), 1);
    std::string grid[5];
    for(auto &row : grid)
    {
        std::cin >> row;
    }
    int answer = 0;
    do
    {
        std::array<int, 7> cells;
        int count = 0, sCount = 0;
        for(int i = 0; i < 25; i++)
        {
            if(chosen[i])
            {
                cells[count++] = i;
                sCount += grid[i / 5][i % 5] == 'S';
            }
        }
        if(sCount >= 4 && isConnected(cells))
        {
            answer++;
        }
    }
    while(std::next_permutation(chosen.begin(), chosen.end()));
    std::cout << answer << '\n';
    return 0;
}
