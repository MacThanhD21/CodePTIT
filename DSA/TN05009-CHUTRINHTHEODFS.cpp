#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

const int N = 1005;
vector<int> adj[N];
int n, m;
bool vis[N];
string ans;

bool dfs(int u, string s, int par)
{
    vis[u] = true;
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            int ok = dfs(v, s + " " + to_string(v), u);
            if (ok)
            {
                return true;
            }
        }
        else if (v != par && v == 1)
        {
            ans = (s + " 1");
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
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ans.clear();
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
        adj[i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
        sort(all(adj[i]));
    }
    if (dfs(1, "1", -1))
        cout << ans << "\n";
    else
        cout << "NO\n";
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