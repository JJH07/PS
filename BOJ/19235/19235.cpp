#include <iostream>
#include <vector>

void stack_brick(std::vector<std::vector<int>> &map, int x, int y, int type, int idx)
{
    int pos = -1;
    for(int i = (type == 3) ? x + 2 : x + 1; i < 6; i++)
    {
        if(map[i][y] > 0)
        {
            break;
        }
        if(type == 2 && (map[i][y + 1] > 0))
        {
            break;
        }
        pos = i;
    }
    if(pos == -1)
    {
        return ;
    }
    map[x][y] = 0;
    map[pos][y] = idx;
    if(type == 2)
    {
        map[x][y + 1] = 0;
        map[pos][y + 1] = idx;
    }
    if(type == 3)
    {
        map[x + 1][y] = 0;
        map[pos - 1][y] = idx;
    }
}
int get_point(std::vector<std::vector<int>> &map)
{
    int ret = 0;
    for(int i = 2; i < 6; i++)
    {
        int tot = 0;
        for(int j = 0; j < 4; j++)
        {
            if(map[i][j] > 0)
            {
                tot++;
            }
        }
        if(tot == 4)
        {
            ret++;
            for(int j = 0; j < 4; j++)
            {
                map[i][j] = 0;
            }
        }
    }
    return ret;
}
void reorder(std::vector<std::vector<int>> &map)
{
    for(int i = 4; i >= 0; i--)
    {
        for(int j = 0; j < 4; j++)
        {
            if(map[i][j] == 0)
            {
                continue;
            }
            if(j > 0 && map[i][j - 1] == map[i][j])
            {
                continue;
            }
            else if(i < 5 && map[i][j] == map[i + 1][j])
            {
                continue;
            }
            else if(j < 3 && map[i][j] == map[i][j + 1])
            {
                stack_brick(map, i, j, 2, map[i][j]);
            }
            else if(i > 0 && map[i][j] == map[i - 1][j])
            {
                stack_brick(map, i - 1, j, 3, map[i][j]);
            }
            else
            {
                stack_brick(map, i, j, 1, map[i][j]);
            }
        }
    }
}
void check(std::vector<std::vector<int>> &map)
{
    int count = 0;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(map[i][j] > 0)
            {
                count++;
                break;
            }
        }
    }
    if(count == 0)
    {
        return ;
    }
    for(int i = 5 - count; i >= 0; i--)
    {
        for(int j = 0; j < 4; j++)
        {
            map[i + count][j] = map[i][j];
        }
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            map[i][j] = 0;
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::vector<int>> blue(6, std::vector<int>(4, 0)), green(6, std::vector<int>(4, 0));
    int n, brick_cnt = 0, point = 0;
    std::cin >> n;
    while(n--)
    {
        brick_cnt++;
        int t, x, y, pts;
        std::cin >> t >> x >> y;

        blue[0][x] = brick_cnt;
        green[0][y] = brick_cnt;
        if(t == 2)
        {
            blue[1][x] = brick_cnt;
            green[0][y + 1] = brick_cnt;
        }
        if(t == 3)
        {
            blue[0][x + 1] = brick_cnt;
            green[1][y] = brick_cnt;
        }

        int b_brick_type = (t == 1) ? 1 : (t == 2) ? 3 : 2;
        int g_brick_type = t;

        stack_brick(blue, 0, x, b_brick_type, brick_cnt);
        while((pts = get_point(blue)) > 0)
        {
            point += pts;
            reorder(blue);
        }
        check(blue);

        stack_brick(green, 0, y, g_brick_type, brick_cnt);
        while((pts = get_point(green)) > 0)
        {
            point += pts;
            reorder(green);
        }
        check(green);
    }
    int rest = 0;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(blue[i][j] > 0)
            {
                rest++;
            }
            if(green[i][j] > 0)
            {
                rest++;
            }
        }
    }
    std::cout << point << '\n' << rest << '\n';
    return 0;
}