#include <iostream>
#include <vector>

int n, root;
std::vector<int> IN, POST, pos;
void find(int in_s, int in_e, int post_s, int post_e)
{
    if(in_s > in_e || post_s > post_e)
    {
        return ;
    }
    int root = POST[post_e];
    int root_pos = pos[root];

    std::cout << root << ' ';

    int L_size = root_pos - in_s;
    find(in_s, root_pos - 1, post_s, post_s + L_size - 1);
    find(root_pos + 1, in_e, post_s + L_size, post_e - 1);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n;
    IN.resize(n);
    POST.resize(n);
    pos.resize(n + 1);
    for(int i = 0; i < n; i++)
    {
        std::cin >> IN[i];
    }
    for(int i = 0; i < n; i++)
    {
        std::cin >> POST[i];
    }
    for(int i = 0; i < n; i++)
    {
        pos[IN[i]] = i; 
    }
    find(0, n - 1, 0, n - 1);
    return 0;
}