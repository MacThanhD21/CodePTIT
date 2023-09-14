
/*

    Cho cây nhị phân, nhiệm vụ của bạn là dịch chuyển cây nhị phân
     
    thành cây nhị phân tìm kiếm. Phép dịch chuyển phải bảo toàn được 
    
    cấu trúc cây nhị phân ban đầu. Ví dụ dưới đây sẽ minh họa phép dịch chuyển:

    C:\Users\ADMIN\Downloads\download (15).png

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa 
    
    vào số N là số lượng cạnh của cây; dòng tiếp theo đưa 
    
    vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, 
    
    x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được 
    
    viết cách nhau một vài khoảng trống.

    T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;

Output:

    Đưa ra kết quả mỗi test theo từng dòng là phép duyệt Inorder của cây tìm kiếm.
Ví dụ:

Input                               Output

2
2
1 2 R 1 3 L                         1 2 3
4
10 20 L 10 30 R 20 40 L 20 60 R     10 20 30 40 60

*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int u) : data(u), left(nullptr), right(nullptr) {}
};

node *BST(node *&root, int x)
{

    if (!root)
        return new node(x);

    if (x > root->data)
    {
        root->right = BST(root->right, x);
    }
    else
    {
        root->left = BST(root->left, x);
    }
    return root;
}

void inOrder(node *root)
{
    if (!root)
        return;

    if (root->left)
        inOrder(root->left);
    cout << root->data << " ";
    if (root->right)
        inOrder(root->right);
}

void solve()
{
    int n;
    cin >> n;
    string s[10005];

    set<int> se;
    vector<int> a(10005, 0);

    for (int i = 1; i <= n * 3; i++)
    {
        cin >> s[i];
        if (isdigit(s[i][0]))
        {
            se.insert(stoi(s[i]));
        }
    }
    node *root = NULL;
    for (auto x : se)
    {
        root = BST(root, x);
    }
    inOrder(root);
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