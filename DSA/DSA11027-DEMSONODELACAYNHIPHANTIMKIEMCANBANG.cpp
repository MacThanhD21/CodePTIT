
/*

    Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số 
    
    A[] =(a0, a1, .., an-1}. Đếm số node lá của cây nhị phân tìm kiếm cân bằng.  
    
    Ví dụ với dãy A[]={40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30} ta sẽ có 
    
    phép duyệt theo thứ tự trước của cây nhị phân tìm kiếm cân bằng với số 
    
    node lá là 5 : 15, 23, 30, 35 45.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T (T≤100).

    Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm 2 dòng: 
    
    dòng thứ nhất là số tự nhiên N (N≤1000). Dòng tiếp theo là N số của mảng A[].

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Input                                                       Output

2

11

40  28  45 38  33  15  25  20  23  35  30                   4

10

1  2  3  4  5  6  7  8  9  10                               4

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

// Build cay Nhi Phan Tim Kiem Cam Bang

node *build(node *root, int a[], int l, int r)
{
    if (l > r)
        return NULL;

    int mid = (l + r) / 2; // luôn tìm thằng ở giữa dãy con đã sắp xếp làm gốc

    root = new node(a[mid]);
    root->left = build(root, a, l, mid - 1);
    root->right = build(root, a, mid + 1, r);
    return root;
}
int ans = 0;
void countLeaf(node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        ++ans;
    }
    if (root->left != NULL)
        countLeaf(root->left);
    if (root->right != NULL)
        countLeaf(root->right);
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        root = build(root, a, 0, n - 1);
        ans = 0;
        countLeaf(root);
        cout << ans << "\n";
    }
}