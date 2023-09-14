

/*

    Đường đi đơn trên đồ thị có hướng hoặc vô hướng đi qua tất cả các đỉnh 
    
    của đồ thị mỗi đỉnh đúng một lần được gọi là đường đi Hamilton. 
    
    Cho đồ thị vô hướng G = <V, E>, hãy kiểm tra xem đồ thị có đường đi Hamilton hay không?

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào hai số 
    
    V, E tương ứng với số đỉnh, số cạnh của đồ thị;
    
    phần thứ hai đưa vào các cạnh của đồ thị.

    T, V, E thỏa mãn ràng buộc: 1≤T ≤100; 1≤V≤10; 1≤ E ≤15.

Output:

    Đưa ra 1 hoặc 0 tương ứng với test có hoặc không có đường đi Hamilton theo từng dòng.
Ví dụ:

Input                           Output

2
4 4                             1
1 2 2 3 3 4 2 4
4 3                             0
1 2 2 3 2 4

*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1005];
bool used[1005];
bool check;

void dfs(int u, int dem)
{
    used[u] = true;
    // cout << dem << "\n";
    if (dem == n)
    {
        check = true;
        return;
    }
    for (auto x : adj[u])
    {
        if (!used[x])
        {
            dfs(x, dem + 1);
        }
    }
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool ok = false;
    for (int i = 1; i <= n; i++)
    {
        check = false;
        memset(used, false, sizeof(used));
        dfs(i, 1);
        if (check)
        {
            ok = true;
            break;
        }
    }
    if (ok)
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        used[i] = false;
    }
    check = false;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}