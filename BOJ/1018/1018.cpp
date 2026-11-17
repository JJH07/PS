#include <iostream>
#include <string>
typedef std::pair<int, int> Point;
int rowCount, columnCount;
std::string board[50];
int countRepaints(int startRow, int startColumn)
{
    int patternMismatches = 0, inversePatternMismatches = 0;
    for(int row = startRow; row < startRow + 8; row++)
    {
        for(int column = startColumn; column < startColumn + 8; column += 2)
        {
            if(row % 2)
            {
                board[row][column] == 'W' ? ++patternMismatches : ++inversePatternMismatches;
            }
            else
            {
                board[row][column] == 'W' ? ++inversePatternMismatches : ++patternMismatches;
            }
        }
        for(int column = startColumn + 1; column < startColumn + 8; column += 2)
        {
            if(row % 2)
            {
                board[row][column] == 'B' ? ++patternMismatches : ++inversePatternMismatches;
            }
            else
            {
                board[row][column] == 'B' ? ++inversePatternMismatches : ++patternMismatches;
            }
        }
    }
    return std::min(patternMismatches, inversePatternMismatches);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int minimumRepaints = 2501;
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