
/*

    Cho cây nhị phân có giá trị mỗi node là một số, nhiệm vụ của bạn 

    là tìm tổng lớn nhất từ một node lá này sang một node lá khác? 
    
    Ví dụ với cây dưới đây ta có tổng lớn nhất là 27.

    C:\Users\ADMIN\Downloads\download (14).png
    
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

Input                                                                                       Output

1
12
-15 5 L -15 6 R 5 -8 L 5 1 R -8 2 L -8 -3 R 6 3 L 6 9 R 9 0 R 0 4 L 0 -1 R -1 10 L          27


*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int u) : data(u), left(NULL), right(NULL) {}
};

void makeNode(node *root, int u, int v, char c)
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
        makeNode(root, u, v, c);
    }
    else
    {
        addNode(root->left, u, v, c);
        addNode(root->right, u, v, c);
    }
}

int res = -1e9;

int sumMax(node *root)
{
    if (!root)
        return 0;
    int sumL = sumMax(root->left);
    int sumR = sumMax(root->right);
    if (!root->left && !root->right)
        return root->data;
    if (!root->left)
        return sumR + root->data;
    if (!root->right)
        return sumL + root->data;

    if (root->left && root->right)
    {
        res = max(res, sumR + sumL + root->data);
        return max(sumL, sumR) + root->data;
    }
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
        if (root == NULL)
        {
            root = new node(u);
            makeNode(root, u, v, c);
        }
        else
        {
            addNode(root, u, v, c);
        }
    }
    res = -1e9;
    sumMax(root);
    cout << res << "\n";
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