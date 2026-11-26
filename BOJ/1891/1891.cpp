#include <iostream>
#include <string>
#include <utility>

using ll = long long;

std::pair<ll, ll> decode(const std::string &code, ll size)
{
    ll row = 0, col = 0;
    for(char digit : code)
    {
        size /= 2;
        if(digit == '3' || digit == '4')
        {
            row += size;
        }
        if(digit == '1' || digit == '4')
        {
            col += size;
        }
    }
    return {row, col};
}

std::string encode(ll row, ll col, ll size, int depth)
{
    std::string code;
    code.reserve(depth);
    for(ll half = size / 2; half > 0; half /= 2)
    {
        if(row >= half)
        {
            code += col >= half ? '4' : '3';
            row -= half;
        }
        else
        {
            code += col >= half ? '1' : '2';
        }
        if(col >= half)
        {
            col -= half;
        }
    }
    return code;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int depth;
    std::string code;
    ll dx, dy;
    std::cin >> depth >> code >> dx >> dy;
    const ll size = 1LL << depth;
    auto [row, col] = decode(code, size);
    row -= dy;
    col += dx;
    if(row < 0 || col < 0 || row >= size || col >= size)
    {
        std::cout << "-1\n";
        return 0;
    }
    std::cout << encode(row, col, size, depth) << '\n';
    return 0;
}
