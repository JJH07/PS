#include <iostream>
#include <string>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string number;
    while(1)
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