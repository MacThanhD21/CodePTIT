

/*

    Cho hai mảng là phép duyệt Inorder và Level-order, 

    nhiệm vụ của bạn là xây dựng cây nhị phân và đưa ra kết quả 

    phép duyệt Postorder. Level-order là phép duyệt theo từng mức của cây. 

    Ví dụ như cây dưới đây ta có phép Inorder và Level-order như dưới đây:

    Inorder : 4  8  10  12 14 20 22

    Level order: 20  8  22  4  12  10  14

    C:\Users\ADMIN\Downloads\download (10).png

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào 
    
    số N là số lượng node; dòng tiếp theo đưa vào N 
    
    số là phép duyệt Inorder; dòng cuối cùng đưa vào 
    
    N số là phép duyệt Level-order; các số được viết 
    
    cách nhau một vài khoảng trống.

    T, N, node thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤A[i]≤104;

Output:

    Đưa ra kết quả phép duyệt Postorder theo từng dòng.
Ví dụ:

Input                   Output

2
3
1 0 2                   1 2 0
0 1 2 
7
3 1 4 0 5 2 6           3 4 1 5 6 2 0
0 1 2 3 4 5 6 

*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int u) : data(u), left(nullptr), right(nullptr) {}
};

node *build(node *root, vector<int> &in, vector<int> &level, int st, int en, unordered_map<int, int> &mp)
{
    if (st > en)
        return nullptr;

    int rootVal = level[0];

    root = new node(rootVal);

    int rootIdx = mp[rootVal];

    int n = level.size();

    vector<int> leftLevel;
    vector<int> rightLevel;

    for (int i = 1; i < n; i++)
    {
        int val = level[i];
        if (find(in.begin() + st, in.begin() + rootIdx, val) != in.begin() + rootIdx)
        {
            leftLevel.push_back(val);
        }
        else
        {
            rightLevel.push_back(val);
        }
    }
    root->left = build(root, in, leftLevel, st, rootIdx - 1, mp);

    root->right = build(root, in, rightLevel, rootIdx + 1, en, mp);

    return root;
}

void postOrder(node *root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);

    cout << root->data << " ";
}
void solve()
{
    int n;
    cin >> n;
    vector<int> in(n);
    vector<int> level(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
        mp[in[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> level[i];
    }

    node *root = build(root, in, level, 0, n - 1, mp);

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