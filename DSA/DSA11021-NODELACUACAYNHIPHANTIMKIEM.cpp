

/*

    Cho dãy số gồm N số là phép duyệt theo thứ tự trước (Preorder) của một 
    
    cây nhị phân tìm kiếm. Hãy in ra tất cả các node lá của cây ?

    Ví dụ với dãy A[] = {30, 20, 15, 25, 23, 28, 40, 35, 33, 38, 45} là phép 
    
    duyệt cây theo thứ tự trước sẽ cho ta kết quả: 15, 23, 28, 33, 38, 45.                                           

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T (T≤100).

    Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm 2 dòng: 
    
    dòng thứ nhất là số tự nhiên N (N≤1000). 
    
    Dòng tiếp theo là N số là phép duyệt theo 
    
    thứ tự trước của cây BST.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input                                       Output

2

6

10 5 1 7 40 50                              1 7 50

11

30 20 15 25 23 28 40 35 33 38 45            15 23 28 33 38 45

*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node
{
    int data;
    node *left, *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
// cach insert1
void insertNode1(node *&root, int x)
{
    if (root == NULL)
    {
        root = new node(x);
        return;
    }
    if (x < root->data)
        insertNode1(root->left, x);
    else if (x > root->data)
        insertNode1(root->right, x);
}
// cach insert2
node *insertNode2(node *root, int x)
{
    if (root == NULL)
    {
        return new node(x);
    }
    if (x < root->data)
    {
        root->left = insertNode2(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = insertNode2(root->right, x);
    }
    return root;
}
vector<int> leaf;
void leafOfBST(node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        leaf.push_back(root->data);
    }
    if (root->left)
        leafOfBST(root->left);
    if (root->right)
        leafOfBST(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        leaf.clear();
        node *root = NULL;
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
            // insertNode1(root, x);
            root = insertNode2(root, x);
        }
        leafOfBST(root);
        for (auto x : leaf)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}