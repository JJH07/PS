#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int t, mem_sz, brfck_len, pr_len;
    std::string brainfck, program;
    
    std::cin >> t;
    while(t--)
    {
        std::cin >> mem_sz >> brfck_len >> pr_len;
        std::cin >> brainfck >> program;
        
        int memory[100001] = {0, }, loop_pair[4097], loop_e = -1, pointer = 0, program_idx = 0, counter = 0;
        bool flag = false;
        
        
        std::stack<int> stk;
        for(int i = 0; i < brfck_len; i++)
        {
            if(brainfck[i] == '[')
            {
                stk.push(i);
            }
            else if(brainfck[i] == ']')
            {
                loop_pair[stk.top()] = i;
                loop_pair[i] = stk.top();
                stk.pop();
            }
        }
        
        for(int i = 0; i < brfck_len; i++)
        {
            counter++;
            if(brainfck[i] == '-')
            {
                memory[pointer] == 0 ? memory[pointer] = 255 : memory[pointer]--;
            }
            else if(brainfck[i] == '+')
            {
                memory[pointer] == 255 ? memory[pointer] = 0 : memory[pointer]++;
            }
            else if(brainfck[i] == '<')
            {
                pointer == 0 ? pointer = mem_sz - 1 : pointer--;
            }
            else if(brainfck[i] == '>')
            {
                pointer == mem_sz - 1 ? pointer = 0 : pointer++;
            }
            else if(brainfck[i] == '[')
            {
                if(memory[pointer] == 0)
                {
                    i = loop_pair[i];
                    continue;
                }
            }
            else if(brainfck[i] == ']')
            {
                if(memory[pointer] != 0)
                {
                    loop_e = std::max(loop_e, i);
                    i = loop_pair[i];
                    continue;
                }
            }
            else if(brainfck[i] == ',')
            {
                if(program_idx == pr_len)
                {
                    memory[pointer] = 255;
                }
                else
                {
                    memory[pointer] = (int)program[program_idx++];
                }
            }
            if(counter > 50000000)
            {
                flag = true;
                break;
                
            }
        }
        if(flag)
        {
            std::cout << "Loops " << loop_pair[loop_e] << ' ' << loop_e << '\n';
        }
        else
        {
            std::cout << "Terminates\n";
        }
    }
    
    return 0;
}
