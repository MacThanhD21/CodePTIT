
/*

    Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số 
    
    A[] =(a0, a1, .., an-1}. Đưa ra nội dung node gốc của cây 
    
    tìm kiếm cân bằng.  Ví dụ với dãy A[]={40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30} 
    
    ta sẽ có cây nhị phân tìm kiếm cân bằng với node gốc là 33.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T (T≤100).

    Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm 2 dòng: 
    
    dòng thứ nhất là số tự nhiên N (N≤106). Dòng tiếp theo là N số của mảng A[].

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input                                                   Output

2

11

40  28  45 38  33  15  25  20  23  35  30               30

10

1  2  3  4  5  6  7  8  9  10                           5

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
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        sort(a, a + n);
        int m = (0 + n - 1) / 2;
        cout << a[m] << "\n";
    }
}