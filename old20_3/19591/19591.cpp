#include <iostream>
#include <deque>
#include <string>
typedef long long ll;
std::string str;
std::deque<ll> opd;
std::deque<char> opt;
void parse()
{
    int str_len = (int)str.length();
    int idx = 0;
    while(idx < str_len)
    {
        ll number = 0;
        bool MINUS = false;
        if(str[idx] == '-')
        {
            MINUS = true;
            idx++;
        }
        for(idx; idx < str_len; idx++)
        {
            if(str[idx] < '0' || str[idx] > '9')
            {
                break;
            }
            number = number * 10 + (str[idx] - '0');
        }
        if(MINUS)
        {
            number *= -1;
        }
        opd.push_back(number);
        if(idx < str_len)
        {
            opt.push_back(str[idx]);
            idx++;
        }
    }
}
ll calc_front()
{
    ll num1 = opd[0];
    ll num2 = opd[1];
    char opt1 = opt.front();
    ll ret;
    switch(opt1){
        case '+':
            ret = num1 + num2;
            break;
        case '-':
            ret = num1 - num2;
            break;
        case '*':
            ret = num1 * num2;
            break;
        case '/':
            ret = num1 / num2;
            break;
    }
    return ret;
}
ll calc_back()
{
    int sz = (int)opd.size();
    ll num1 = opd[sz - 2];
    ll num2 = opd[sz - 1];
    char opt1 = opt.back();
    ll ret;
    switch(opt1){
        case '+':
            ret = num1 + num2;
            break;
        case '-':
            ret = num1 - num2;
            break;
        case '*':
            ret = num1 * num2;
            break;
        case '/':
            ret = num1 / num2;
            break;
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> str;
    parse();

    while(!opt.empty())
    {
        int front_opt = (opt.front() == '*' || opt.front() == '/') ? 1 : 0;
        int back_opt = (opt.back() == '*' || opt.back() == '/') ? 1 : 0;
        if(front_opt == back_opt)
        {
            ll front = calc_front();
            ll back = calc_back();
            if(front >= back)
            {
                opd.pop_front();
                opd.pop_front();
                opt.pop_front();
                opd.push_front(front);
            }
            else
            {
                opd.pop_back();
                opd.pop_back();
                opt.pop_back();
                opd.push_back(back);
            }
        }
        else if(front_opt > back_opt)
        {
            ll front = calc_front();
            opd.pop_front();
            opd.pop_front();
            opt.pop_front();
            opd.push_front(front);
        }
        else
        {
            ll back = calc_back();
            opd.pop_back();
            opd.pop_back();
            opt.pop_back();
            opd.push_back(back);
        }
    }
    std::cout << opd.front() << '\n';
    return 0;
}