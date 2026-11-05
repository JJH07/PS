#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 10

char phone_number[10000][MAX + 1];
struct trie{
    bool Finish;
    trie *child[MAX];
    trie() : Finish(false) {
        std::memset(child, 0, sizeof(child));
    }
    ~trie() {
        for(int i = 0; i < MAX; i++)
        {
            if(child[i])
            {
                delete child[i];
            }
        }
    }
    void insert(const char *pn)
    {
        if(*pn == 0)
        {
            Finish = true;
        }
        else
        {
            int next = pn[0] - '0';
            if(child[next] == 0)
            {
                child[next] = new trie();
            }   
            child[next]->insert(pn + 1);
        }
    }
    bool find(const char *pn)
    {
        if(*pn == 0)
        {
            return true;
        }
        if(Finish)
        {
            return false;
        }
        int next = pn[0] - '0';
        return child[next]->find(pn + 1);
    }
};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        trie *root = new trie();
        int n;
        bool FLAG = false;
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            std::cin >> phone_number[i];
            root->insert(phone_number[i]);
        }
        for(int i = 0; i < n; i++)
        {
            if(root->find(phone_number[i]) == false)
            {
                FLAG = true;
                break;
            }
        }
        std::cout << (FLAG ? "NO\n" : "YES\n");
        delete(root);
    }
    return 0;
}