

/*

    Cho một mảng A[] gồm N phần tử. Nhiệm vụ của bạn là đưa ra 1 
    
    nếu mảng A[] biểu diễn phép duyệt inorder của cây nhị phân tìm kiếm, 
    
    ngược lại đưa ra 0.

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N 
    
    là số lượng node của cây tìm kiếm; dòng tiếp theo đưa vào N số A[i]; 
    
    các số được viết cách nhau một vài khoảng trống.

    T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤A[i]≤104;

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input                       Output

3
5
10 20 30 40 50              1
6
90 80 100 70 40 30          0
3
1 1 2                       0

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
    else if (x > root->data)
    {
        root->right = insertNode2(root->right, x);
    }
    return root;
}
vector<int> b;
void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    preOrder(root->left);
    b.push_back(root->data);
    preOrder(root->right);
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
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
            // insertNode1(root, x);
            root = insertNode2(root, x);
        }
        preOrder(root);
        bool ok = true;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                ok = false;
                break;
            }
        }
        if (ok)
            cout << "1\n";
        else
            cout << "0\n";
        // cout << "\n";
        b.clear();
    }
}
