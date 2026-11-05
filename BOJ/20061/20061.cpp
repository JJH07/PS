#include <iostream>
#include <cstring>
#include <vector>

std::vector<std::vector<int>> green(6, std::vector<int>(4));
std::vector<std::vector<int>> blue(6, std::vector<int>(4));
int Points;

int find_x(std::vector<std::vector<int>> &map, int y)
{
    int ret = 5;
    for(int i = 0; i < 6; i++)
    {
        if(map[i][y])
        {
            ret = i - 1;
            break;
        }
    }
    return ret;
}
void stack(int type, int x, int y)
{
    if(type == 1)
    {
        green[find_x(green, y)][y] = 1;
        blue[find_x(blue, x)][x] = 1;
    }
    else if(type == 2)
    {
        int nx = std::min(find_x(green, y), find_x(green, y + 1));
        green[nx][y] = 1;
        green[nx][y + 1] = 1;
        blue[find_x(blue, x)][x] = 1;
        blue[find_x(blue, x)][x] = 1;
    }
    else
    {
        green[find_x(green, y)][y] = 1;
        green[find_x(green, y)][y] = 1;
        int nx = std::min(find_x(blue, x), find_x(blue, x + 1));
        blue[nx][x] = 1;
        blue[nx][x + 1] = 1;
    }
}
void realloc()
{
    int g_x = 5, b_x = 5;
    while(g_x >= 2)
    {
        int count = green[g_x][0] + green[g_x][1] + green[g_x][2] + green[g_x][3];
        if(count == 4)
        {
            for(int i = g_x; i > 0; i--)
            {
                for(int j = 0; j < 4; j++)
                {
                    green[i][j] = green[i - 1][j];
                }
            }
            green[0][0] = green[0][1] = green[0][2] = green[0][3] = 0;
            Points++;
        }
        else
        {
            g_x--;
        }
    }
    int top;
    if(green[0][0] || green[0][1] || green[0][2] || green[0][3])
    {
        top = 2;
    }
    else if(green[1][0] || green[1][1] || green[1][2] || green[1][3])
    {
        top = 1;
    }
    else
    {
        top = 0;
    }
    if(top > 0)
    {
        for(int i = 5; i >= top; i--)
        {
            for(int j = 0; j < 4; j++)
            {
                green[i][j] = green[i - top][j];
            }
        }
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                green[i][j] = 0;
            }
        }
    }

    while(b_x >= 2)
    {
        int count = blue[b_x][0] + blue[b_x][1] + blue[b_x][2] + blue[b_x][3];
        if(count == 4)
        {
            for(int i = b_x; i > 0; i--)
            {
                for(int j = 0; j < 4; j++)
                {
                    blue[i][j] = blue[i - 1][j];
                }
            }
            blue[0][0] = blue[0][1] = blue[0][2] = blue[0][3] = 0;
            Points++;
        }
        else
        {
            b_x--;
        }
    }
    if(blue[0][0] || blue[0][1] || blue[0][2] || blue[0][3])
    {
        top = 2;
    }
    else if(blue[1][0] || blue[1][1] || blue[1][2] || blue[1][3])
    {
        top = 1;
    }
    else
    {
        top = 0;
    }
    if(top > 0)
    {
        for(int i = 5; i >= top; i--)
        {
            for(int j = 0; j < 4; j++)
            {
                blue[i][j] = blue[i - top][j];
            }
        }
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                blue[i][j] = 0;
            }
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    while(n--)
    {
        int t, x, y;
        std::cin >> t >> x >> y;
        stack(t, x, y);
        realloc();
    }
    int tile_cnt = 0;
    for(int i = 2; i < 6; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            tile_cnt += green[i][j] + blue[i][j];
        }
    }
    std::cout << Points << '\n' << tile_cnt << '\n';
    return 0;
}