#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>

struct pos{
    int x, y;
    pos(){}
    pos(int X, int Y) : x(X), y(Y){}
};
struct stk_n{
    int x, y, d, cnt;
    stk_n(int X, int Y, int D, int C) : x(X), y(Y), d(D), cnt(C){}
};

pos s, e;

int r, c, tot_block;
std::string map[25];
int visited[25][25];

char block[9] = " 1234|-+";
int pipe[8][4] = {{-1, -1, -1, -1}, {3, 2, -1, -1}, {-1, 0, 3, -1}, {-1, -1, 1, 0}, {1, -1, -1, 2}, {0, -1, 2, -1}, {-1, 1, -1, 3}, {0, 1, 2, 3}};
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int is_PIPE(char c)
{
    int ret = -1;
    switch(c)
    {
        case '1':
            ret = 1;
            break;
        case '2':
            ret = 2;
            break;
        case '3':
            ret = 3;
            break;
        case '4':
            ret = 4;
            break;
        case '|':
            ret = 5;
            break;
        case '-':
            ret = 6;
            break;
        case '+':
            ret = 7;
            break;
        default :
            break;
    }
    return ret;
}
stk_n dfs(stk_n start)
{
    std::stack<stk_n> stk;

    stk.push(start);
    visited[start.x][start.y] = 1;
    while(!stk.empty())
    {
        auto [x, y, d, cnt] = stk.top();
        int nx = dx[d] + x;
        int ny = dy[d] + y;
        if(nx < 0 || ny < 0 || nx >= r || ny >= c || map[nx][ny] == '.' ||  map[nx][ny] == 'M')
        {
            break;
        }
        int p = is_PIPE(map[nx][ny]);
        int nd = pipe[p][d];
        if(p == 7)
        {
            if(visited[nx][ny] >= 2)
            {
                break;
            }
            else
            {
                visited[nx][ny]++;
                stk.push(stk_n(nx, ny, nd, visited[nx][ny] == 1 ? cnt + 1 : cnt));
            }
        }
        else
        {
            if(visited[nx][ny] == 1)
            {
                break;
            }
            else
            {
                visited[nx][ny] = 1;
                stk.push(stk_n(nx, ny, nd, cnt + 1));
            }
        }
    }
    return stk.top();
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> r >> c;
    for(int i = 0; i < r; i++)
    {
        std::cin >> map[i];
        for(int j = 0; j < c; j++)
        {
            if(map[i][j] == 'M')
            {
                s.x = i;
                s.y = j;
                visited[i][j] = 1;
            }
            else if(map[i][j] == 'Z')
            {
                e.x = i;
                e.y = j;
            }
            if(map[i][j] != '.')
            {
                tot_block++;
            }
        }
    }

    stk_n top(-1, -1, -1, -1);
    for(int i = 0; i < 4; i++)
    {
        int nx = dx[i] + s.x;
        int ny = dy[i] + s.y;
        if(nx < 0 || ny < 0 || nx >= r || ny >= c || map[nx][ny] == '.' || map[nx][ny] == 'Z')
        {
            continue;
        }
        int nd = pipe[is_PIPE(map[nx][ny])][i];
        if(nd >= 0)
        {
            top = {nx, ny, nd, 1};
        }
    }
    if(top.d == -1)
    {
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + s.x;
            int ny = dy[i] + s.y;
            if(nx < 0 || ny < 0 || nx >= r || ny >= c || map[nx][ny] != '.')
            {
                continue;
            }
            for(int p = 1; p <= 7; p++)
            {
                std::memset(visited, 0, sizeof(visited));
                visited[s.x][s.y] = 1;
                visited[nx][ny] = 1;

                int nd = pipe[p][i];
                if(nd < 0)
                {
                    continue;
                }
                map[nx][ny] = block[p];
                stk_n ans = dfs({nx, ny, nd, 1});
                if(map[ans.x][ans.y] == 'Z' && ans.cnt == tot_block)
                {
                    std::cout << nx + 1 << ' ' << ny + 1 << ' ' << map[nx][ny] << '\n';
                    return 0;
                }
            }
        }
    }
    else
    {
        int keep[r][c];
        stk_n t = dfs(top);
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                keep[i][j] = visited[i][j];
            }
        }
        
        int sx = dx[t.d] + t.x;
        int sy = dy[t.d] + t.y;

        for(int p = 1; p <= 7; p++)
        {
            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    visited[i][j] = keep[i][j];
                }
            }

            int nd = pipe[p][t.d];
            if(nd < 0)
            {
                continue;
            }
            map[sx][sy] = block[p];
            visited[sx][sy] = 1;
            stk_n ans = dfs({sx, sy, nd, t.cnt});

            if(map[ans.x][ans.y] == 'Z' && ans.cnt + 1 == tot_block)
            {
                std::cout << sx + 1 << ' ' << sy + 1 << ' ' << map[sx][sy] << '\n';
                break;
            }
        }
    }
    return 0;
}