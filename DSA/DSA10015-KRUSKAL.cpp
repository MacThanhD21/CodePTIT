

/*

    Cho đồ thị vô hướng có trọng số G=<V, E, W>. Nhiệm vụ của bạn 
    
    là hãy xây dựng một cây khung nhỏ nhất của đồ thị bằng thuật toán Kruskal.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 

    Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào 
    
    hai số V, E tương ứng với số đỉnh và số cạnh của đồ thị; 
    
    phần thứ 2 đưa vào E cạnh của đồ thị, mỗi cạnh là một bộ 3: 
    
    đỉnh đầu, đỉnh cuối và trọng số của cạnh.

    T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤V≤100; 1≤E, W≤10000.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input               Output

2
3 3                 4
1 2 5
2 3 3
1 3 1

2 1                 5
1 2 5

*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ms(a) memset(a, false, sizeof(a))
#define ii pair<int, int>
#define ll long long

const int N = 100005;

struct edge
{
    int x, y, w;
};

vector<edge> adj;
int n, m;
int par[N], sz[N];

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        par[i] = sz[i] = 0;
    }
    adj.clear();
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edge tmp = {x, y, w};
        adj.pb(tmp);
    }
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}
int Find(int u)
{
    if (u == par[u])
        return u;
    return par[u] = Find(par[u]);
}
bool Combine(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return false;
    if (sz[x] < sz[y])
        swap(x, y);
    sz[y] += sz[x];
    par[x] = y;
    return true;
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

void KrusKal()
{
    int ans = 0;
    sort(all(adj), cmp);

    // duyet qua m canh
    for (int i = 0; i < m; i++)
    {
        // lấy 2 cạnh của đồ thị và gộp lại
        int x = adj[i].x, y = adj[i].y, w = adj[i].w;
        if (Combine(x, y))
        {
            ans += w;
        }
    }
    cout << ans << "\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        init();
        KrusKal();
    }
}