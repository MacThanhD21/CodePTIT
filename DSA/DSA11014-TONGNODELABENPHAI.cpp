

/*

    Cho cây nhị phân, nhiệm vụ của bạn là tính tổng của tất cả các node 

    lá bên phải trên cây? Ví dụ với cây dưới đây ta có kết quả là 2.

    C:\Users\ADMIN\Downloads\download (13).png

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào 
    
    số N là số lượng cạnh của cây; dòng tiếp theo đưa 
    
    vào N bộ ba (u, v, x), trong đó u là node cha, 
    
    v là node con, x= R nếu v là con phải, x=L nếu v là con trái; 
    
    u, v, x được viết cách nhau một vài khoảng trống.

    T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input                                                   Output

2
2
1 2 L 1 3 R                                             3
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L                 60

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct node
{
    int data;
    node *left, *right;

    node(int u) : data(u), left(nullptr), right(nullptr) {}
};

void add(int u, int v, char c, map<int, node *> &mp)
{
    if (c == 'L')
    {
        mp[u]->left = new node(v);
        mp[v] = mp[u]->left;
    }
    else
    {
        mp[u]->right = new node(v);
        mp[v] = mp[u]->right;
    }
}

ll sum = 0;

void sumLeafOfRight(node *root)
{
    if (!root)
        return;

    if (root->right && !(root->right->left) && !(root->right->right))
    {
        sum += root->right->data;
    }

    if (root->left)
        sumLeafOfRight(root->left);
    if (root->right)
        sumLeafOfRight(root->right);
}

void solve()
{
    int n;
    cin >> n;
    node *root = nullptr;

    map<int, node *> mp;

    for (int i = 1; i <= n; i++)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;

        if (!root)
        {
            root = new node(u);

            mp[u] = root;

            if (c == 'L')
            {
                root->left = new node(v);
                mp[v] = root->left;
            }
            else if (c == 'R')
            {
                root->right = new node(v);
                mp[v] = root->right;
            }
        }
        else
        {
            add(u, v, c, mp);
        }
    }
    sum = 0;
    sumLeafOfRight(root);
    cout << sum << "\n";
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