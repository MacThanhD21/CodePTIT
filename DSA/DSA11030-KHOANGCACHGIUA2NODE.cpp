

/*

    Cho một cây có N node, gốc tại 1. Có Q truy vấn, mỗi truy vấn yêu cầu bạn 
    
    tìm khoảng cách giữa hai node u và v.

    C:\Users\ADMIN\Downloads\download (17).png
    
Input:

    Dòng đầu tiên là số lượng bộ test T( T≤ 20).

    Mỗi test bắt đầu bằng số nguyên N (1 ≤ N ≤ 1000).
     
    N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên 
    
    u, v cho biết node u nối với node v.

    Dòng tiếp theo là số lượng truy vấn Q (1 ≤ Q ≤ 1000). 
    
    Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên u và v.

Output: 

    Với mỗi test, in ra Q dòng là đáp án với mỗi truy vấn.

Ví dụ:

Input                       Output

1

8

1 2                         2

1 3                         4

2 4                         3

2 5                         1

3 6                         5

3 7

6 8

5

4 5

4 6

3 4

2 4

8 5

*/

#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second

vector<int> adj[1005];
bool vis[1005];

void bfs(int u, int v)
{
    queue<ii> Q;
    Q.push({u, 0});
    memset(vis, false, sizeof(vis));
    vis[u] = true;
    while (!Q.empty())
    {
        ii top = Q.front();
        Q.pop();

        if (top.fi == v)
        {
            cout << top.second << "\n";
            return;
        }
        for (auto x : adj[top.fi])
        {
            if (!vis[x])
            {
                vis[x] = true;
                Q.push({x, top.se + 1});
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = false;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        bfs(x, y);
        // cout << x << " " << y << "\n";
    }
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