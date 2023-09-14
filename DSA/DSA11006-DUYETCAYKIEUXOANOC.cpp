
/*

    Cho cây nhị phân, nhiệm vụ của bạn là duyệt cây theo xoắn ốc (spiral-order). 

    Ví dụ với cây dưới đây sẽ cho ta kết quả của phép duyệt spiral-order: 1 2 3 4 5 6 7.

    C:\Users\ADMIN\Downloads\download (12).png
    
Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N 
    
    là số lượng cạnh của cây; dòng tiếp theo đưa vào N 
    
    bộ ba (u, v, x), trong đó u là node cha, v là node con, 
    
    x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được 
    
    viết cách nhau một vài khoảng trống.

    T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;

Output:

    Đưa ra kết quả phép duyệt level-order theo từng dòng.

Ví dụ:

Input                                       Output

2
2
1 2 R 1 3 L                                 1 3 2
4
10 20 L 10 30 R 20 40 L 20 60 R             10 20 30 60 40
*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void makeRoot(node *root, int u, int v, char c)
{
    if (c == 'L')
        root->left = new node(v);
    else
        root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c)
{
    if (root == NULL)
        return;
    if (root->data == u)
    {
        makeRoot(root, u, v, c);
    }

    else
    {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

void spiral(node *root)
{
    stack<node *> s1, s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            node *a = s1.top();
            s1.pop();
            cout << a->data << " ";
            if (a->right != NULL)
            {
                s2.push(a->right);
            }
            if (a->left != NULL)
            {
                s2.push(a->left);
            }
        }
        while (!s2.empty())
        {
            node *b = s2.top();
            s2.pop();
            cout << b->data << " ";
            if (b->left != NULL)
            {
                s1.push(b->left);
            }
            if (b->right != NULL)
            {
                s1.push(b->right);
            }
        }
    }
    cout << "\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        node *root = NULL;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (root == NULL)
            {
                root = new node(u);
                makeRoot(root, u, v, c);
            }
            else
            {
                insertNode(root, u, v, c);
            }
        }
        spiral(root);
    }
}