

/*

    Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
    
    Sử dụng thuật toán DFS, hãy kiểm tra xem đồ thị có tồn tại chu trình hay không?

Input:

    Dòng đầu tiên đưa vào T là số lượng bộ test.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số 
    
    |V|, |E| tương ứng với số đỉnh,  số cạnh của đồ thị; 
    
    Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.

    T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

    Đưa ra YES hoặc “NO” kết quả test theo từng dòng tương ứng 
    
    với đồ thị tồn tại hoặc không tồn tại chu trình.
Ví dụ:

Input:                                      Output:

1

6 9  

1 2 2 4 3 1 3 2 3 5 4 3 5 4 5 6 6 4         YES

*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

vector<int> adj[MAXN];
vector<int> res;

int n, m;
int vis[MAXN], inDegree[MAXN];

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }
}

bool topologicalSort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
    if (res.size() != n)
        return true;
    return false;
}

void solve()
{
    memset(vis, 0, sizeof(vis));
    memset(inDegree, 0, sizeof(inDegree));
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
    }
    res.clear();
    init();
    if (topologicalSort())
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
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// Cách 2 :
/*
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

const int N = 1005;
vector<int> adj[N]; // danh sach ke : O(V + E)
bool vs[N] = {false};
int n, m;
int deg[1005];
int coun;

void BFS_Kahn()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
            ++coun;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            --deg[v];
            if (deg[v] == 0)
            {
                q.push(v);
                ++coun;
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            vs[i] = false;
            deg[i] = 0;
        }
        coun = 0;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            deg[y]++;
        }
        for (int i = 1; i <= n; i++)
        {
            sort(all(adj[i]));
        }
        BFS_Kahn();
        // cout << coun << '\n';
        if (coun != n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
*/