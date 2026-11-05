#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct node{
    std::string name;
    int level;
    std::map<std::string, int> next;
    node(std::string N, int L) : name(N), level(L){
        next.clear();
    }
};
std::vector<node> tree;
void Print(int index)
{
    if(index > 0)
    {
        for(int i = 0; i < tree[index].level - 1; i++)
        {
            std::cout << "--";
        }
        std::cout << tree[index].name << '\n';
    }
    std::vector<std::string> namelist;
    for(auto x : tree[index].next)
    {
        namelist.push_back(x.first);
    }
    std::sort(namelist.begin(), namelist.end());
    for(auto x : namelist)
    {
        Print(tree[index].next[x]);
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    tree.push_back(node("Start", 0));

    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int depth;
        std::cin >> depth;
        int pidx = 0;
        for(int lv = 1; lv <= depth; lv++)
        {
            std::string name;
            std::cin >> name;
            if(tree[pidx].next.find(name) == tree[pidx].next.end())
            {
                tree.push_back(node(name, lv));
                tree[pidx].next[name] = tree.size() - 1;
            }
            pidx = tree[pidx].next[name];
        }
    }
    Print(0);
    return 0;
}