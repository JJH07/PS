#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string str, key, ans;
    std::stack<char> stk;
    std::cin >> str >> key;
    int key_sz = (int)key.length();
    std::reverse(key.begin(), key.end());
    for(auto c : str)
    {
        stk.push(c);
        
        std::string tmp;
        int idx = 0;
        bool FLAG = false;
        while(idx < key_sz)
        {
            if(stk.empty() || stk.top() != key[idx])
            {
                FLAG = true;
                break;
            }
            stk.pop();
            tmp += key[idx];
            idx++;
        }
        if(FLAG)
        {
            for(auto x = tmp.rbegin(); x != tmp.rend(); x++)
            {
                stk.push(*x);   
            }
        }
    }
    while(!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    if(ans.empty())
    {
        std::cout << "FRULA\n";
    }
    else
    {
        std::reverse(ans.begin(), ans.end());
        std::cout << ans << '\n';
    }
}