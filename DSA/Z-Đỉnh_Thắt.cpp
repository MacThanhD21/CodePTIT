#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
vector<int> adj[1005];
bool used[1005];
vector<string> res;

void dfs(int u, string ans)
{
    used[u] = true;
    
    for (auto x : adj[u])
    {
        if (!used[x])
        {
            dfs(x, ans + to_string(x));
            used[x] = false;
            if (x == v)
            {
                ans += to_string(v);
                res.push_back(ans);
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> u >> v;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        used[i] = false;
    }
    res.clear();
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    dfs(u, to_string(u));

    // cout << res.size() << " ";

    int fre[1005] = {0};

    for (auto x : res)
    {
        for (auto z : x)
        {
            string tmp = "";
            tmp += z;
            z = stoi(tmp);
            fre[z]++;
        }
    }

    int anss = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i != u && i != v)
        {
            if (fre[i] == res.size())
            {
                ++anss;
                // cout << i << " " << fre[i] << "\n";
            }
        }
    }
    cout << anss << "\n";
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
