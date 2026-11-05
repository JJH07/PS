#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define MAX 100001
typedef long long ll;
struct query{
    int i, j, offset;
};
int n, m, list[MAX];
ll tree[MAX * 4];
std::vector<query> update_query, print_query[MAX];
std::vector<std::pair<int, ll>> answer;
void update_tree(int node, int start, int end, int idx, int val){
    if(idx < start || end < idx){
        return ;
    }
    if(start == end){
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    update_tree(node * 2, start, mid, idx, val);
    update_tree(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll sum(int node, int start, int end, int left, int right){
    if(end < left || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}
int main() {
    fastio;
    std::cin >> n;
    for(int i = 1; i <= n; i++){
        int v;
        std::cin >> v;
        update_tree(1, 1, n, i, v);
    }
    std::cin >> m;
    for(int idx = 0; idx < m; idx++){
        int type;
        std::cin >> type;
        if(type == 1){
            int i, v;
            std::cin >> i >> v;
            update_query.push_back({i, v, 0});
        }
        else{
            int k, i, j;
            std::cin >> k >> i >> j;
            print_query[k].push_back({i, j, idx});
        }
    }

    int updateq_sz = (int)update_query.size();
    for(int i = 0; i <= updateq_sz; i++){
        if(i > 0){
            query uqry = update_query[i - 1];
            update_tree(1, 1, n, uqry.i, uqry.j);
        }
        for(auto pqry : print_query[i]){
            ll ans = sum(1, 1, n, pqry.i, pqry.j);
            answer.push_back(std::make_pair(pqry.offset, ans));
        }
    }
    std::sort(answer.begin(), answer.end());
    for(auto x : answer){
        std::cout << x.second << '\n';
    }
    return 0;
}