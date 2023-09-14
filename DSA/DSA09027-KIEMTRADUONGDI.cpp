
/*

    Cho đồ thị vô hướng có N đỉnh và M cạnh. Có Q truy vấn, 
    
    mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh x và y 
    
    có tồn tại đường đi tới nhau hay không?

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm 2 số nguyên N, M (1 ≤ N, M ≤ 1000).

    M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v 
    
    cho biết có cạnh nối giữa đỉnh u và v.

    Dòng tiếp là số lượng truy vấn Q (1 ≤ Q ≤ 1000).

    Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên x và y.

Output:  

    Với mỗi truy vấn, in ra “YES” nếu có đường đi 
    
    từ x tới y, in ra “NO” nếu ngược lại.

Ví dụ:

Input                       Output

1

6 5                         

1 2

2 3

3 4

1 4

5 6

2           

1 5                         NO

2 4                         YES

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
int coun;
int pro[1005];

void DFS(int u)
{
    pro[u] = coun;
    visited[u] = true;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            DFS(v);
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
        int v, e;
        cin >> v >> e;
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for (int i = 1; i <= v; i++)
        {
            sort(all(adj[i]));
        }
        for (int i = 1; i <= v; i++)
        {
            if (!visited[i])
            {
                ++coun;
                DFS(i);
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int s, t;
            cin >> s >> t;
            if (pro[s] == pro[t])
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
        for (int i = 1; i <= v; i++)
        {
            adj[i].clear();
            pro[i] = 0;
            visited[i] = 0;
        }
        coun = 0;
    }
}