

/*

    Cho một mảng A[] gồm N phần tử biểu diễn phép duyệt preorder của 
    
    cây nhị phân tìm kiếm. Nhiệm vụ của bạn là đưa ra phép duyệt postorder 
    
    của cây nhị phân tìm kiếm.

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N 
    
    là số lượng node của cây tìm kiếm; dòng tiếp theo đưa vào 
    
    phép duyệt preorder của cây tìm kiếm; các số được viết 
    
    cách nhau một vài khoảng trống.

    T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤A[i]≤104;

Output:

    Đưa ra kết quả mỗi test theo từng dòng là phép duyệt postorder của cây tìm kiếm.

Ví dụ:

Input                           Output

2
5
40 30 35 80 100                 35 30 100 80 40
8
40 30 32 35 80 90 100 120       35 32 30 120 100 90 80 40

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
    else
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
    else
    {
        root->right = insertNode2(root->right, x);
    }
    return root;
}
void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << ' ';
    // cout << "\n";
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
        node *root = NULL;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            // insertNode1(root, x);
            root = insertNode2(root, x);
        }
        preOrder(root);
        cout << "\n";
    }
}
