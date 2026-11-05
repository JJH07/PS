#include <iostream>
#include <vector>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> data(m);
    std::vector<int> person(n + 1), predict(n + 1), double_check(n + 1);
    for(int i = 0; i < m; i++)
    {
        int k;
        std::cin >> k;
        for(int j = 0; j < k; j++)
        {
            int t;
            std::cin >> t;
            data[i].push_back(t);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        std::cin >> person[i];
    }
    predict = person;
    for(int i = m - 1; i >= 0; i--)
    {
        int infect = 0, ninfect = 0;
        bool check = false;
        for(int idx : data[i])
        {
            predict[idx] ? infect++ : ninfect++;
            if(infect > 0 && ninfect > 0)
            {
                check = true;
                break;
            }
        }
        if(check)
        {
            for(int idx : data[i])
            {
                predict[idx] = 0;
            }
        }
    }
    double_check = predict;
    for(int i = 0; i < m; i++)
    {
        int infect = 0, ninfect = 0;
        bool check = false;
        for(int idx : data[i])
        {
            double_check[idx] ? infect++ : ninfect++;
            if(infect > 0 && ninfect > 0)
            {
                check = true;
                break;
            }
        }
        if(check)
        {
            for(int idx : data[i])
            {
                double_check[idx] = 1;
            }
        }
    }
    bool ans = true;
    for(int i = 1; i <= n; i++)
    {
        if(double_check[i] != person[i])
        {
            ans = false;
            break;
        }
    }
    if(ans)
    {
        std::cout << "YES\n";
        for(int i = 1; i <= n; i++)
        {
            std::cout << predict[i] << ' ';
        }
        std::cout << '\n';
    }
    else
    {
        std::cout << "NO\n";
    }
    return 0;
}