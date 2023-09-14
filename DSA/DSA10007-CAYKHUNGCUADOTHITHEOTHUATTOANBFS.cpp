

/*

    Cho đồ thị vô hướng G=(V, E). Hãy xây dựng một cây khung của đồ thị G 
    
    với đỉnh u ∈ V là gốc của cây bằng thuật toán BFS.

Input

    Dòng đầu tiên gồm một số nguyên T (1 ≤ T ≤ 20) là số lượng bộ test.

    Tiếp theo là T bộ test, mỗi bộ test có dạng sau:

    Dòng đầu tiên gồm 3 số nguyên N=|V|, M=|E|, 
    
    u (1 ≤ N ≤ 103, 1 ≤ M ≤ 105, 1 ≤ u ≤ N).

    M dòng tiếp theo, mỗi dòng gồm 2 số nguyên a, b 
    
    (1 ≤ a, b ≤ N, a ≠ b) tương ứng cạnh nối hai chiều từ a tới b.

    Dữ liệu đảm bảo giữa hai đỉnh chỉ tồn tại nhiều nhất một cạnh nối.

Output

    Với mỗi bộ test, nếu tồn tại cây khung thì in ra N – 1 
    
    cạnh của cây khung với gốc là đỉnh u trên N – 1 dòng theo 
    
    thứ tự duyệt của thuật toán BFS. Ngược lại nếu không 
    
    tồn tại cây khung thì in ra -1.

Ví dụ

Input                   Output

2

4 4 2

1 2                     2 1

1 3                     2 4

2 4                     1 3 

3 4

4 2 2                   -1

1 2

3 4

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<int, int>
#define v vector
#define pb push_back

int n, m, s;
vector<int> adj[100005];
vector<ii> cicirl;
bool visited[100005];

void bfs(int u)
{
    queue<int> Q;
    Q.push(u);
    visited[u] = true;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                cicirl.pb({u, v});
                visited[v] = true;
                Q.push(v);
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
        cin >> n >> m >> s;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }
        cicirl.clear();
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        bfs(s);
        // cout << cicirl.size() << "\n";
        if (cicirl.size() != n - 1)
        {
            cout << -1 << "\n";
        }
        else
        {
            for (auto it : cicirl)
            {
                cout << it.first << " " << it.second << "\n";
            }
        }
    }
}