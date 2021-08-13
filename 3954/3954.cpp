#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define MAX 4096

int sm, sc, si;
std::string Program, Input;
int visited[MAX][256];
std::map<int, int> Find_Bracket()
{
    std::map<int, int> ret;
    std::stack<int> stk;

    for(int i = 0; i < sc; i++)
    {
        if(Program[i] == '[')
        {
            stk.push(i);
        }
        else if(Program[i] == ']')
        {
            int top = stk.top();
            stk.pop();
            ret[i] = top;
            ret[top] = i;
        }
    }
    return ret;
}
int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int tc;

    std::cin >> tc;
    while(tc--)
    {
        std::cin >> sm >> sc >> si >> Program >> Input;

        std::memset(visited, 0, sizeof(visited));
        std::map<int, int> Bracket = Find_Bracket();
        std::vector<unsigned char> data(sm, 0);
        int Pointer = 0, program_index = 0, input_index = 0, run = 0;
        int x = MAX, y = -1;
        for(program_index = 0; program_index < sc && run < 100000000; program_index++, run++)
        {
            if(Program[program_index] == '-')
            {
                --data[Pointer]; 
            }
            else if(Program[program_index] == '+')
            {
                ++data[Pointer];
            }
            else if(Program[program_index] == '<')
            {
                Pointer = Pointer == 0 ? sm - 1 : Pointer - 1;
            }
            else if(Program[program_index] == '>')
            {
                Pointer = Pointer == sm - 1 ? 0 : Pointer + 1;
            }
            else if(Program[program_index] == '[')
            {
                if(!data[Pointer])
                {
                    if(run > 50000000)
                    {
                        x = std::min(x, program_index);
                        y = std::max(y, Bracket[program_index]);
                    }
                    program_index = Bracket[program_index];
                }
            }
            else if(Program[program_index] == ']')
            {
                if(data[Pointer])
                {
                    if(run > 50000000)
                    {
                        x = std::min(x, Bracket[program_index]);
                        y = std::max(y, program_index);
                    }
                    program_index = Bracket[program_index];
                }
            }
            else if(Program[program_index] == '.')
            {

            }
            else if(Program[program_index] == ',')
            {
                data[Pointer] = input_index < si ? Input[input_index++] : 255;
            }
            else
            {
                std::cout << "Error! Unknown operator\n";
                return 0;
            }
        }
        if(run < 100000000)
        {
            std::cout << "Terminates\n";
        }
        else
        {
            std::cout << "Loops " << x << ' ' << y << '\n';
        }
    }
}
