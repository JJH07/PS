#include <algorithm>
#include <iostream>
#include <string>
int rowCount, columnCount;
std::string board[50];
int countRepaints(int startRow, int startColumn)
{
    int patternMismatches = 0;
    for(int row = startRow; row < startRow + 8; row++)
    {
        for(int column = startColumn; column < startColumn + 8; column++)
        {
            const char expectedColor = ((row - startRow + column - startColumn) % 2 == 0) ? 'W' : 'B';
            if(board[row][column] != expectedColor)
            {
                patternMismatches++;
            }
        }
    }
    return std::min(patternMismatches, 64 - patternMismatches);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int minimumRepaints = 64;
    std::cin >> rowCount >> columnCount;
    for(int i = 0; i < rowCount; i++)
    {
        std::cin >> board[i];
    }
    for(int i = 0; i <= rowCount - 8; i++)
    {
        for(int j = 0; j <= columnCount - 8; j++)
        {
            minimumRepaints = std::min(minimumRepaints, countRepaints(i, j));
        }
    }
    std::cout << minimumRepaints << '\n';
    return 0;
}
