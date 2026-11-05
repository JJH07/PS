#include <bits/stdc++.h>

struct Fenwick
{
	std::vector<int> tree; int sz;
	Fenwick(int n) : tree(n + 1), sz(n) {}
	void Init()
    {
		for (int i = 1; i <= sz; i++) {
			if(i + (i & -i) <= sz)
            {
				tree[i + (i & -i)] += tree[i];
            }
		}
	}
	void Update(int i, int val)
    {
        while(i <= sz)
        {
            tree[i] += val;
            i += i & -i;
        }
	}
	int Query(int i)
    {
		int ret = 0;
        while(i > 0)
        {
            ret += tree[i];
            i -= i & -i;
        }
        return ret;
	}
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

	int L, ML, MK, C;
    std::cin >> L >> ML >> MK >> C;
	Fenwick fenwick(L);
	for(int i = 1, prev = 0; i <= L; i++)
    {
		int hp;
        std::cin >> hp;
		fenwick.tree[i] = hp - prev;
		prev = hp;
	}
	fenwick.Init();
	for(int i = 1; i <= L; i++)
    {
		if (fenwick.Query(i) <= MK)
        {
            fenwick.Update(i, -MK);
            fenwick.Update(i + ML, MK);
        }
		else
        {
            C--;
        }
	}
	std::cout << (C >= 0 ? "YES" : "NO") << '\n';
    return 0;
}