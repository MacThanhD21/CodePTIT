
/*

    Cho mảng A[] gồm N node là biểu diễn phép duyệt theo thứ tự trước 
    
    (Preorder) của cây nhị phân tìm kiếm. Nhiệm vụ của bạn là đưa ra phép duyệt 
    
    theo thứ tự sau của cây nhị phân tìm kiếm.

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N 
    
    là số lượng node; dòng tiếp theo đưa vào N số A[i]; 
    
    các số được viết cách nhau một vài khoảng trống.

    T, N, node thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤A[i]≤104;

Output:

    Đưa ra kết quả phép duyệt Postorder theo từng dòng.

Ví dụ:

Input                           Output

2
5
40 30 35 80 100                 35 30 100 80 40
8
40 30 32 35 80 90 100 120       35 32 30 120 100 90 80 40

*/

#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int u) : data(u), left(nullptr), right(nullptr) {}
};

void add(node *&root, int x)
{
    if (!root)
    {
        root = new node(x);
        return;
    }

    if (x < root->data)
    {
        add(root->left, x);
    }
    else
    {
        add(root->right, x);
    }
}

void postOrder(node *root)
{
    if (root->left)
        postOrder(root->left);
    if (root->right)
        postOrder(root->right);
    cout << root->data << " ";
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
        add(root, x);
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