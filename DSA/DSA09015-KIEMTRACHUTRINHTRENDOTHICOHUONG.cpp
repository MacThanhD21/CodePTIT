

/*

    Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
    
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

Input:                                  Output:

1

6 9  

1 2 2 4 3 1 3 2 3 5 4 3 5 4 5 6 6 4     YES

*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

const int N = 1005;
vector<int> adj[N]; // danh sach ke : O(V + E)
bool vs[N] = {false};
vector<int> topo;
int n, m;
int deg[1005];
int coun;
vector<int> V;

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
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            deg[y]++;
        }
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            vs[i] = false;
            deg[i] = 0;
        }
        coun = 0;
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
// - Cách 2 :
/*
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1005;
vector<int> graph[MAX];
bool visited[MAX];
bool stack[MAX];

bool DFS(int u) {
    visited[u] = true;
    stack[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            if (DFS(v)) return true;
        } else if (stack[v]) {
            return true;
        }
    }
    stack[u] = false;
    return false;
}

bool hasCycle(int n) {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        stack[i] = false;
    }
    for (int u = 1; u <= n; u++) {
        if (!visited[u]) {
            if (DFS(u)) return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }
        if (hasCycle(n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
*/
// - Cách 3:
/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX = 1005;
vector<int> graph[MAX];
int index[MAX], lowlink[MAX];
bool onStack[MAX];
stack<int> nodeStack;
int currentIndex = 0;

void tarjanSCC(int u, vector<vector<int>> &SCCs)
{
    index[u] = currentIndex;
    lowlink[u] = currentIndex;
    currentIndex++;
    nodeStack.push(u);
    onStack[u] = true;

    for (int v : graph[u])
    {
        if (index[v] == -1)
        {
            tarjanSCC(v, SCCs);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (onStack[v])
        {
            lowlink[u] = min(lowlink[u], index[v]);
        }
    }

    if (lowlink[u] == index[u])
    {
        vector<int> SCC;
        int v;
        do
        {
            v = nodeStack.top();
            nodeStack.pop();
            onStack[v] = false;
            SCC.push_back(v);
        } while (v != u);
        SCCs.push_back(SCC);
    }
}

bool hasCycle(int n)
{
    vector<vector<int>> SCCs;
    for (int i = 1; i <= n; i++)
    {
        index[i] = -1;
        onStack[i] = false;
    }
    for (int u = 1; u <= n; u++)
    {
        if (index[u] == -1)
        {
            tarjanSCC(u, SCCs);
        }
    }
    for (vector<int> SCC : SCCs)
    {
        if (SCC.size() > 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            graph[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }
        if (hasCycle(n))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
*/