

/*

    Cho cây nhị phân, nhiệm vụ của bạn là duyệt cây theo Level-order. 

    Phép duyệt level-order trên cây là phép thăm node theo từng mức của cây. 

    Ví dụ với cây dưới đây sẽ cho ta kết quả của phép duyệt level-order: 

    20  8  22  4  12  10  14.

    C:\Users\ADMIN\Downloads\download (9).png


Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào 
    
    số N là số lượng cạnh của cây; dòng tiếp theo đưa 
    
    vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, 
    
    x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được 
    
    viết cách nhau một vài khoảng trống.
    
    T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;

Output:

    Đưa ra kết quả phép duyệt level-order theo từng dòng.
Ví dụ:

Input                                   Output

2
2
1 2 R 1 3 L                             1 3 2
4
10 20 L 10 30 R 20 40 L 20 60 R         10 20 30 40 60

*/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void make(node *root, int u, int v, char c)
{
    if (c == 'L')
    {
        root->left = new node(v);
    }
    else if (c == 'R')
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

void level_order(node *root)
{
    if (!root)
        return;

    queue<node *> Q;
    Q.push(root);
    while (Q.size())
    {
        auto top = Q.front();
        Q.pop();
        cout << top->data << " ";

        if (top->left)
            Q.push(top->left);
        if (top->right)
            Q.push(top->right);
    }
    cout << "\n";
}
void solve()
{
    int n;
    cin >> n;
    node *root = NULL;
    while (n--)
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
    level_order(root);
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