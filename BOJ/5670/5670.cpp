#include <iostream>
#include <string>
#include <vector>
#define MAX 26
struct trie{
    bool end;
    trie *child[MAX];
    int child_cnt;
    trie() : end(false), child_cnt(0)
    {
        for(int i = 0; i < MAX; i++)
        {
            child[i] = nullptr;
        }
    }
    ~trie()
    {
        for(int i = 0; i < MAX; i++)
        {
            if(child[i])
            {
                delete child[i];
            }
        }
    }
    void insert(const char *word)
    {
        if(*word == '\0')
        {
            end = true;
            return ;
        }
        int idx = word[0] - 'a';
        if(!child[idx])
        {
            child[idx] = new trie();
            child_cnt++;
        }
        child[idx]->insert(word + 1);
    }
};
int dfs(const trie *t, int w)
{
    int ret = t->end ? w : 0;
    for(int i = 0; i < MAX; i++)
    {
        if(t->child[i] == nullptr)
        {
            continue;
        }
        if(t->child_cnt + t->end == 1)
        {
            ret += dfs(t->child[i], w);
        }
        else
        {
            ret += dfs(t->child[i], w + 1);
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(2);
    int n;
    char temp[85];
    trie *root;
    while(!(std::cin >> n).eof())
    {
        root = new trie();
        for(int i = 0; i < n; i++)
        {
            std::cin >> temp;
            root->insert(temp);
        }
        int pushed = 0;
        for(int i = 0; i < MAX; i++)
        {
            if(root->child[i])
            {
                pushed += dfs(root->child[i], 1);
            }
        }
        std::cout << (double)pushed / (double)n << '\n';
        delete(root);
    }
    return 0;
}