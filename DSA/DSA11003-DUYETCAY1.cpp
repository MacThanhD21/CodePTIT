
/*

    Cho phép duyệt cây nhị phân Inorder và Preorder, hãy đưa ra kết quả phép duyệt 
    
    Postorder của cây nhị phân. Ví dụ với cây nhị phân có các phép duyệt cây nhị phân 
    
    của cây dưới đây:

           1
        /    \    
       2      3
     /   \     \
    4     5     6

    Inorder     : 4  2  5  1  3  6

    Preorder:  : 1  2  4  5  3  6

    Postorder : 4  5  2  6  3  1 

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số 
    
    N là số lượng node; dòng tiếp theo đưa vào N số theo phép 
    
    duyệt Inorder; dòng cuối cùng đưa vào N số là kết quả của phép duyệt 
    
    Preorder; các số được viết cách nhau một vài khoảng trống.

    T, N, node thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤1000; 1≤ giá trị node ≤104;
    
Output:

    Đưa ra kết quả phép duyệt Postorder theo từng dòng.

Ví dụ:

Input                           Output

1

6
4  2  5  1  3  6                4  5  2  6  3  1

1  2  4  5  3  6

*/

#include <iostream>
#include <unordered_map>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    // Constructor
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *buildTree(node *root, int in[], int pre[], int st, int en, int &preIdx, unordered_map<int, int> mp)
{
    if (st > en)
        return nullptr;

    int rootVal = pre[preIdx];
    preIdx++;
    root = new node(rootVal);

    int rootIdx = mp[rootVal];

    root->left = buildTree(root, in, pre, st, rootIdx - 1, preIdx, mp);

    root->right = buildTree(root, in, pre, rootIdx + 1, en, preIdx, mp);

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
    int in[n], pre[n];

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
        mp[in[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    int preIdx = 0;
    node *root = buildTree(root, in, pre, 0, n - 1, preIdx, mp);
    postOrder(root);
    cout << "\n";
}

int main()
{
    int T = 1;
    cin >> T;

    while (T--)
    {
        solve();
    }
}