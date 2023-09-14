
/*

    Cho một mảng là phép duyệt level-order của cây nhị phân tìm kiếm. 
    
    Nhiệm vụ của bạn là xây dựng lại cây nhị phân tìm kiếm bảo toàn được 
    
    cấu trúc cây nhị phân ban đầu.

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm dòng: dòng đầu tiên đưa vào số N là 
    
    số lượng node của cây tìm kiếm; dòng tiếp theo đưa vào 
    
    phép duyệt level-order của cây tìm kiếm; các số được 
    
    viết cách nhau một vài khoảng trống.

    T, N, node thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤node≤104;

Output:

    Đưa ra kết quả mỗi test theo từng dòng là phép duyệt trước (preOrder) của cây tìm kiếm.
Ví dụ:

Input                       Output

2
9
7 4 12 3 6 8 1 5 10         7 4 3 1 6 5 12 8 10
6
1 3 4 6 7 8                 7 4 3 1 6 5 12 8 10

*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int u) : data(u), left(NULL), right(NULL) {}
};

node *addNode(node *root, int x)
{
    if (!root)
    {
        return new node(x);
    }
    if (x < root->data)
    {
        root->left = addNode(root->left, x);
    }
    else
    {
        root->right = addNode(root->right, x);
    }
    return root;
}

void postOrder(node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    if (root->left)
        postOrder(root->left);
    if (root->right)
        postOrder(root->right);
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    node *root = NULL;
    for (auto &x : a)
    {
        cin >> x;
        root = addNode(root, x);
    }
    postOrder(root);
    cout << "\n";
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