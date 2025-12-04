#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define MAX 100000
typedef long long ll;
int N, D;
ll tree[MAX * 4];

void update(int node, int start, int end, int idx, ll val){
    if(idx < start || end < idx){
        return;
    }
    if(start == end){
        tree[node] = val;
        return;
    }
    update(node * 2, start, (start + end) / 2, idx, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
    tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
}
ll query(int node, int start, int end, int left, int right){
    if(right < start || end < left){
        return LLONG_MIN;
    }
    if(left <= start && end <= right){
        return tree[node];        
    }
    return std::max(query(node * 2, start, (start + end) / 2, left, right), query(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int main() {
    fastio;
    std::fill(tree, tree + MAX*4, LLONG_MIN);
    std::cin >> N >> D;
    for(int i = 1; i <= N; i++)
    {
        int K;
        std::cin >> K;
        int l = (i - D >= 1 ? i - D : 1);
        int r = (i - 1 >= 1 ? i - 1 : 1);
        ll res = std::max(0LL, query(1, 1, N, l, r)) + K;
        update(1, 1, N, i, res);
    }
    ll ans = query(1, 1, N, 1, N);
    std::cout << ans << '\n';
    return 0;
}