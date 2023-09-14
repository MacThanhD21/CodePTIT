

/*

    Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có phải 
    
    là một cây hoàn hảo hay không (perfect tree)? Một cây nhị phân được gọi 
    
    là cây hoàn hảo nếu tất cả các node trung gian của nó đều có hai node con 
    
    và tất cả các node lá đều có cùng một mức.

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào 
    
    số N là số lượng cạnh của cây; dòng tiếp theo 
    
    đưa vào N bộ ba (u, v, x), trong đó u là node cha, 
    
    v là node con, x= R nếu v là con phải, x=L nếu v là con trái; 
    
    u, v, x được viết cách nhau một vài khoảng trống.

    T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input                                                       Output

3
6
10 20 L 10 30 R 20 40 L 20 50 R 30 60 L 30 70 R             Yes
2
18 15 L 18 30 R                                             Yes
5
1 2 L 2 4 R 1 3 R 3 5 L 3 6 R                               No

*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int u)
    {
        data = u;
        left = right = NULL;
    }
};

void makeNode(node *root, int u, int v, char c)
{
    if (c == 'L')
    {
        root->left = new node(v);
    }
    else
    {
        root->right = new node(v);
    }
}

void addNode(node *root, int u, int v, char c)
{
    if (!root)
        return;

    if (root->data == u)
    {
        makeNode(root, u, v, c);
    }
    else
    {
        addNode(root->left, u, v, c);
        addNode(root->right, u, v, c);
    }
}
bool ok = true;
set<int> se;

void perFect_Tree(node *root, int h)
{
    if (!root)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        se.insert(h);
    }
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
    {
        ok = false;
        return;
    }
    perFect_Tree(root->left, h + 1);
    perFect_Tree(root->right, h + 1);
}
void solve()
{
    int n;
    cin >> n;
    node *root = NULL;
    while (n--)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (root == NULL)
        {
            root = new node(u);
            makeNode(root, u, v, c);
        }
        else
        {
            addNode(root, u, v, c);
        }
    }
    ok = true;
    se.clear();
    perFect_Tree(root, 0);
    if (se.size() == 1 && ok == true)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}