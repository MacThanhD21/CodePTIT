
/*

    Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem tất cả 

    các node lá của cây có cùng một mức hay không? Ví dụ với cây dưới đây 

    sẽ cho ta kết quả là Yes.

    C:\Users\ADMIN\Downloads\download (11).png

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào 
    
    số N là số lượng cạnh của cây; dòng tiếp theo đưa 
    
    vào N bộ ba (u, v, x), trong đó u là node cha, 
    
    v là node con, x= R nếu v là con phải, x=L nếu v là con trái; 
    
    u, v, x được viết cách nhau một vài khoảng trống.

    T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input                                       Output

2

2
1 2 R 1 3 L                                 1

4
10 20 L 10 30 R 20 40 L 20 60 R             0
*/

#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int u) : data(u), left(nullptr), right(nullptr) {}
};

void make(node *root, int u, int v, char c)
{
    if (c == 'L')
    {
        root->left = new node(v);
    }
    else
    {
        root->right = new node(v);
    }
}

void addNode(node *root, int u, int v, char c)
{
    if (!root)
        return;

    if (root->data == u)
    {
        make(root, u, v, c);
    }
    else
    {
        addNode(root->left, u, v, c);
        addNode(root->right, u, v, c);
    }
}

set<int> se;

void checkLeaf(node *root, int height)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        se.insert(height);
        return;
    }

    if (root->left)
    {
        checkLeaf(root->left, height + 1);
    }
    if (root->right)
    {
        checkLeaf(root->right, height + 1);
    }
}

void solve()
{
    int n;
    cin >> n;
    node *root = nullptr;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;

        if (!root)
        {
            root = new node(u);
            make(root, u, v, c);
        }
        else
        {
            addNode(root, u, v, c);
        }
    }
    se.clear();
    checkLeaf(root, 0);
    if (se.size() == 1)
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }
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