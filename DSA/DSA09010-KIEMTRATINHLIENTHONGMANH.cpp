
/*
    Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
    
    Hãy kiểm tra xem đồ thị có liên thông mạnh hay không?

Input:

    Dòng đầu tiên đưa vào T là số lượng bộ test.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số 
    
    |V|, |E| tương ứng với số đỉnh và số cạnh; 
    
    Dòng tiếp theo đưa vào các bộ đôi u, v 
    
    tương ứng với một cạnh của đồ thị.

    T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

    Đưa ra “YES”, hoặc “NO” theo từng dòng tương ứng với 
    
    test là liên thông mạnh hoặc không liên thông mạnh.

Ví dụ:

Input:                                              Output:

1

6 9 

1 2 2 4 3 1 3 2 3 5 4 3 5 4 5 6 6 3                YES

*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

const int N = 1001;
int n, m;
vector<int> adj[N], T_adj[N];
bool visited[N] = {false};
stack<int> st;
int ans = 0;

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        T_adj[y].pb(x);
    }
}
void dfs_one(int u)
{
    visited[u] = true;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            dfs_one(x);
        }
    }
    st.push(u);
}
void dfs_two(int u)
{
    visited[u] = true;
    for (auto x : T_adj[u])
    {
        if (!visited[x])
        {
            dfs_two(x);
        }
    }
}

bool Kosaraju()
{
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs_one(i);
        }
    }
    memset(visited, false, sizeof(visited));
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (!visited[u])
        {
            dfs_two(u);
            ++ans;
        }
    }
    return ans == 1;
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        init();
        if (Kosaraju())
            cout << "YES\n";
        else
            cout << "NO\n";
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            T_adj[i].clear();
            visited[i] = false;
        }
        while (!st.empty())
            st.pop();
    }
}