#include <iostream>
#include <string>
#include <list>

int main()
{
	std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

	int T;
	std::cin >> T;
    while(T--)
    {
		std::list<char> pw;
		std::list<char>::iterator cursor = pw.begin();
		std::string s;
		std::cin >> s;
		for (char c : s)
        {
			if (c == '<')
            {
				if(cursor != pw.begin())
                {
                    cursor--;
                }
			}
			else if (c == '>')
            {
				if(cursor != pw.end())
                {
                    cursor++;
                }
			}
			else if (c == '-')
            {
				if (cursor != pw.begin())
                {
					cursor--;
					cursor = pw.erase(cursor);
				}
			}
			else
            {
				pw.insert(cursor, c);
			}
		}
		for (auto it = pw.begin(); it != pw.end(); it++)
        {
			std::cout << *it;
		}
		std::cout << '\n';
	}
	return 0;
}