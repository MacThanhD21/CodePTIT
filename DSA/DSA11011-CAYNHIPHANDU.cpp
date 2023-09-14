

/*


    Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có 
    
    phải là một cây đủ hay không (full binary tree)? Một cây nhị phân được 
    
    gọi là cây đủ nếu tất cả các node trung gian của nó đều có hai node con.

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

Input                               Output

2
4
1 2 L 1 3 R 2 4 L 2 5 R             1
3
1 2 L 1 3 R 2 4 L                   0

*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node *left;
    node *right;

    node(int value)
    {
        val = value;
        left = right = NULL;
    }
};

void makeNode(node *root, int u, int v, char c)
{
    // u : cha;
    // v : con;
    if (c == 'L')
        root->left = new node(v);
    else
        root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c)
{
    if (root == NULL)
        return;
    if (root->val == u)
        makeNode(root, u, v, c);
    else
        insertNode(root->left, u, v, c), insertNode(root->right, u, v, c);
}
bool ok = true;
void fullTree(node *root) // bat dau tu dinh goc
{
    if (root == NULL)
        return;
    if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
    {
        ok = false;
        return;
    }
    fullTree(root->left);
    fullTree(root->right);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        node *root = NULL;

        for (int i = 0; i < n; i++)
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
                insertNode(root, u, v, c);
            }
        }
        fullTree(root);
        if (ok)
            cout << "1\n";
        else
            cout << "0\n";
        ok = true;
    }
}