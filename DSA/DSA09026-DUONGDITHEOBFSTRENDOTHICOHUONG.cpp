

/*

    Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
    
    Hãy tìm đường đi từ đỉnh uÎV đến đỉnh vÎV trên đồ thị bằng thuật toán BFS.

Input:

    Dòng đầu tiên đưa vào T là số lượng bộ test.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào bốn số 
    
    |V|, |E|, sÎV, tÎV tương ứng với số đỉnh, số cạnh, đỉnh u, đỉnh v; 
    
    |E| Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.

    T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

    Đưa ra đường đi từ đỉnh s đến đỉnh t của mỗi test theo thuật toán BFS của mỗi test theo khuôn dạng của ví dụ dưới đây. Nếu không có đáp án, in ra -1.
Ví dụ:

Input:                                              Output:

1

6 9 1 6

1 2 2 5 3 1 3 2 3 5 4 3 5 4 5 6 6 4                 1 2 5 6

*/


#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO()                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pb push_back

vector<int> adj[1005];
bool visited[1005];
int parent[1005];

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int x : adj[u])
        {
            if (!visited[x])
            {
                parent[x] = u;
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main()
{
    IO();
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
        }
        for (int i = 0; i < n; i++)
        {
            sort(all(adj[i]));
        }
        BFS(s);
        if (visited[t] == false)
            cout << "-1\n";
        else
        {
            vector<int> path;
            while (s != t)
            {
                path.pb(t);
                t = parent[t];
            }
            path.pb(s);
            reverse(all(path));
            for (auto x : path)
            {
                cout << x << " ";
            }
        }
        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            parent[i] = 0;
        }
        memset(visited, false, sizeof(visited));
        cout << "\n";
    }
}