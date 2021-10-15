#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<ll, ll> pii;

ll d, x, y;
std::string n;
pii operator+(pii a, pii b)
{
   return {a.first + b.first, a.second + b.second};
}
pii operator-=(pii &a, pii b)
{
    a.first -= b.first;
    a.second -= b.second;
    return a;
}
pii get_pos(int idx, ll _size)
{
    if(idx == d)
    {
        return {0, 0};
    }
    pii next;
    if(n[idx] == '1')
    {
        next = std::make_pair(0, _size);
    }
    else if(n[idx] == '2')
    {
        next = std::make_pair(0, 0);
    }
    else if(n[idx] == '3')
    {
        next = std::make_pair(_size, 0);
    }
    else
    {  
        next = std::make_pair(_size, _size);
    }
    return next + get_pos(idx + 1, _size / 2);
}
void print(std::string &answer, pii pos, ll _size)
{
    if(_size == 0)
    {
        return ;
    }
    if(pos.first >= _size && pos.second >= _size)
    {
        answer += "4";
        pos -= std::make_pair(_size, _size);
    }
    else if(pos.first >= _size)
    {
        answer += "3";
        pos -= std::make_pair(_size, 0);
    }
    else if(pos.second >= _size)
    {
        answer += "1";
        pos -= std::make_pair(0, _size);
    }
    else
    {
        answer += "2";
    }
    print(answer, pos, _size / 2);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> d >> n >> x >> y;
    ll size = 1LL << d;

    pii Pos = get_pos(0, size / 2);
    Pos.first -= y;
    Pos.second += x;
    if(Pos.first < 0 || Pos.second < 0 || Pos.first >= size || Pos.second >= size)
    {
        std::cout << "-1\n";
        return 0;
    }
    std::string ans;
    print(ans, Pos, size / 2);
    std::cout << ans << '\n';
    return 0;
}