
/*

    Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
    
    Hãy kiểm tra xem đồ thị có tồn tại chu trình hay không?

Input:

    Dòng đầu tiên đưa vào T là số lượng bộ test.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số 
    
    |V|, |E| tương ứng với số đỉnh,  số cạnh của đồ thị; 
    
    Dòng tiếp theo đưa vào các bộ đôi u, v tương ứng với một cạnh của đồ thị.

    T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

    Đưa ra YES hoặc “NO” kết quả test theo từng dòng tương ứng 
    
    với đồ thị tồn tại hoặc không tồn tại chu trình.

Ví dụ:

Input:                                          Output:

1

6  9

1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6             YES

*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ii pair<int, int>

vector<int> adj[1005];
bool visited[1005];
int n, m;

bool dfs(int u, int par)
{
    visited[u] = true;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            if (dfs(x, u))
                return true;
        }
        else
        {
            if (x != par)
                return true;
        }
    }
    return false;
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    bool ok = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
            {
                ok = true;
                break;
            }
        }
    }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        visited[i] = false;
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}