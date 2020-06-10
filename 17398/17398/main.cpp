//
//  main.cpp
//  17398
//
//  Created by 진준호 on 2020/05/11.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

long long ans;
int FIND(int n, std::vector<long long> &root)
{
    if(root[n] < 0)
    {
        return n;
    }
    return root[n] = FIND(root[n], root);
}
void UNION(int a, int b, std::vector<long long40> &root)
{
    int aROOT = FIND(a, root);
    int bROOT = FIND(b, root);
    if(aROOT != bROOT)
    {
        if(root[aROOT] < root[bROOT])
        {
            std::swap(aROOT, bROOT);
        }
        ans += (root[aROOT] * root[bROOT]);
        root[bROOT] += root[aROOT];
        root[aROOT] = bROOT;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::pair<int, int>> connect(m + 1);
    std::vector<int> unlink, init_table(m + 1, 1);
    std::vector<long long> root(n + 1, -1);
    
    for(int i = 1; i <= m; i++)
    {
        std::cin >> connect[i].first >> connect[i].second;
    }
    for(int i = 0; i < q; i++)
    {
        int idx;
        std::cin >> idx;
        unlink.push_back(idx);
        init_table[idx] = 0;
    }
    
    for(int i = 1; i <= m; i++)
    {
        if(init_table[i])
        {
            UNION(connect[i].first, connect[i].second, root);
        }
    }
    
    ans = 0;
    std::reverse(unlink.begin(), unlink.end());
    for(auto x : unlink)
    {
        UNION(connect[x].first, connect[x].second, root);
    }
    std::cout << ans << '\n';
    return 0;
}
