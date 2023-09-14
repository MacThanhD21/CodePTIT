
/*

    Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
    
    Hãy tìm số thành phần liên thông của đồ thị bằng thuật toán BFS.

Input:

    Dòng đầu tiên đưa vào T là số lượng bộ test.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số 
    
    |V|, |E| tương ứng với số đỉnh và số cạnh; 
    
    Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.

    T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

    Đưa ra số thành phần liên thông của đồ thị bằng thuật toán BFS.

Ví dụ:

Input:                          Output:

1

6  6 

1 2 1 3 2 3 3 4 3 5 4 5         2

*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ii pair<int, int>
#define ll long long

vector<int> adj[1005];
int visited[1005];
int n, m;
int parent[1005];

void bfs(int u)
{
    queue<int> Q;
    Q.push(u);
    visited[u] = true;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                Q.push(v);
                visited[v] = true;
            }
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
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(all(adj[i]));
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ++ans;
            bfs(i);
        }
    }
    cout << ans << "\n";
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