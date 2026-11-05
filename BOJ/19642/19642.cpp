#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 350000
struct node{
    std::vector<int> child;
    std::string word;
};
node tree[MAX];
std::string TORIE, KEYWORD;
int tree_size, TORIE_size, KEYWORD_size;
bool FLAG;
int dfs(int parent, int now, int T_idx)
{
    std::string WORD;
    for(T_idx += 1; T_idx < TORIE_size; T_idx++)
    {
        if(TORIE[T_idx] < 'A' || TORIE[T_idx] > 'Z')
        {
            break;
        }
        WORD += TORIE[T_idx];
    }
    tree[now].word = WORD;
    while(TORIE[T_idx] == '[')
    {
        tree[now].child.push_back(++tree_size);
        T_idx = dfs(now, tree_size, T_idx);
    }
    return T_idx + 1;
}
bool solve(int now, int idx)
{
    node &t = tree[now];
    int WORD_size = (int)t.word.size();
    for(int si = 0; si < WORD_size; si++)
    {
        if(t.word[si] != KEYWORD[idx++])
        {
            return false;
        }
        if(idx == KEYWORD_size)
        {
            return true;
        }
    }
    for(int next : t.child)
    {
        if(solve(next, idx))
        {
            return true;
        }
    }
    return false;
}
void search(int now)
{
    node &t = tree[now];
    int WORD_size = (int)t.word.length(), si, ki;
    
    for(int s = 0; s < WORD_size; s++)
    {
        for(si = s, ki = 0; si < WORD_size && ki < KEYWORD_size; si++, ki++)
        {
            if(t.word[si] != KEYWORD[ki])
            {
                break;
            }
        }
        if(ki == KEYWORD_size)
        {
            return;
        }
        if(si == WORD_size)
        {
            for(int next : t.child)
            {
                if(solve(next, ki))
                {
                    return;
                }
            }
        }
    }
    FLAG = true;
    std::cout << '[' << t.word;
    for(int next : t.child)
    {
        search(next);
    }
    std::cout << ']';
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string ans;
    std::cin >> TORIE >> KEYWORD;
    TORIE_size = (int)TORIE.length();
    KEYWORD_size = (int)KEYWORD.length();
    int i = 0;
    while(i < TORIE_size)
    {
        tree[0].child.push_back(++tree_size);
        i = dfs(0, tree_size, i);
    }
    for(int now : tree[0].child)
    {
        search(now);
    }
    std::cout << (FLAG ? "\n" : "torie!\n");
    return 0;
}