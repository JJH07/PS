#include <iostream>
#include <string>
bool valid(int xc, int oc, int xb, int ob)
{
    int diff = xc - oc;
    if(diff < 0 || diff > 2)
    {
        return 0;
    }
    if(xb > 0 && ob > 0)
    {
        return 0;
    }
    if(xb + ob == 0 && xc + oc < 9)
    {
        return 0;
    }
    if(xb > 0 && diff != 1)
    {
        return 0;
    }
    if(ob > 0 && diff != 0)
    {
        return 0;
    }
    return 1;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    while(1)
    {
        std::cin >> s;
        int X_cnt = 0, O_cnt = 0, X_bingo = 0, O_bingo = 0;
        if(s == "end")
        {
            break;
        }
        for(int i = 0; i < 3; i++)
        {
            if(s[i * 3] != '.' && (s[i * 3] == s[i * 3 + 1]) && (s[i * 3] == s[i * 3 + 2]))
            {
                s[i * 3] == 'X' ? X_bingo++ : O_bingo++;
            }
            if(s[i] != '.' && (s[i] == s[i + 3]) && (s[i] == s[i + 6]))
            {
                s[i] == 'X' ? X_bingo++ : O_bingo++;
            }
        }
        if(s[0] != '.' && (s[0] == s[4]) && (s[0] == s[8]))
        {
            s[0] == 'X' ? X_bingo++ : O_bingo++;
        }
        if(s[2] != '.' && (s[2] == s[4]) && (s[2] == s[6]))
        {
            s[2] == 'X' ? X_bingo++ : O_bingo++;
        }

        for(auto x : s)
        {
            if(x == 'X')
            {
                X_cnt++;
            }
            else if(x == 'O')
            {
                O_cnt++;
            }
        }
        if(valid(X_cnt, O_cnt, X_bingo, O_bingo))
        {
            std::cout << "valid\n";
        }
        else
        {
            std::cout << "invalid\n";
        }
    }

    return 0;
}