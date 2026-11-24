#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string number;
    while(true)
    {
        std::cin >> number;
        if(number[0] == '0')
        {
            break;
        }
        int front = 0, back = number.size() - 1;
        while(front < back)
        {
            if(number[front] != number[back])
            {
                break;
            }
            front++;
            back--;
        }
        std::cout << (front >= back ? "yes\n" : "no\n");
    }
    return 0;
}
