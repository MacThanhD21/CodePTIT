

/*

    Đồ thị hai phía là một đồ thị đặc biệt, trong đó tập các đỉnh có thể được 

    chia thành hai tập không giao nhau thỏa mãn điều kiện không có cạnh nối 

    hai đỉnh bất kỳ thuộc cùng một tập. Cho đồ thị N đỉnh và M cạnh, 

    bạn hãy kiểm tra đồ thị đã cho có phải là một đồ thị hai phía hay không?

    C:\Users\ADMIN\Downloads\download (5).png

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤  20).

    Mỗi test bắt đầu bởi số nguyên N và M (1 ≤  N, M ≤  1000).

    M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v 
    
    cho biết có cạnh nối giữa đỉnh u và v.

Output: 

    Với mỗi test, in ra “YES” nếu đồ thị đã cho là một đồ thị hai phía, 
    
    in ra “NO” trong trường hợp ngược lại.
Ví dụ:

Input                   Output

2

5 4                     YES

1 5

1 3

2 3

4 5

3 3                     NO

1 2

1 3

2 3

*/


#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1005];
int color[1005];
int vis[1005];
bool check = true;

void dfs(int u, int c)
{
    color[u] = c;
    for (auto x : adj[u])
    {
        if (color[x] == c)
        {
            check = false;
            return;
        }
        if (color[x] == 0)
        {
            dfs(x, -c);
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        color[i] = 0;
    }
    check = true;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            dfs(i, 1);
        }
    }
    if (check)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}