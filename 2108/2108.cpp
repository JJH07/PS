#include <bits/stdc++.h>
#define MAX 500001
int N, list[MAX];
std::map<int, int> Freq;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(0);

    int Sum = 0, Mode = 0;
    double Avg;

    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        std::cin >> list[i];
        Sum += list[i];
        Freq[list[i]]++;
    }
    
    Avg = (double)Sum / N;
    if(Avg > -0.5 && Avg < 0)
    {
        Avg = 0;
    }
    std::cout << Avg << '\n';

    std::sort(list, list + N);
    std::cout << list[N / 2] << '\n';

    int c = 0, idx;
    for(auto it : Freq)
    {
        if(it.second > c)
        {
            Mode = it.first;
            c = it.second;
            idx = 1;
        }
        else if(it.second == c && idx < 2)
        {
            Mode = it.first;
            idx++;
        }
    }
    std::cout << Mode << '\n';

    std::cout << list[N - 1] - list[0] << '\n';
    return 0;
}