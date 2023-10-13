#include <iostream>
#include <string>
#include <map>
#include <algorithm>
int Max;
std::string Name;
std::map<std::string, int> table;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    while(n--)  
    {
        std::string book;
        std::cin >> book;
        if(table.find(book) == table.end())
        {
            table.insert({book, 1});
        }
        else
        {
            table[book]++;
        }
        if(table[book] < Max)
        {
            continue;
        }
        else if(table[book] > Max)
        {
            Max = table[book];
            Name = book;
        }
        else if(book.compare(Name) < 0)
        {
            Name = book;
        }
    }
    std::cout << Name << '\n';
    return 0;
}