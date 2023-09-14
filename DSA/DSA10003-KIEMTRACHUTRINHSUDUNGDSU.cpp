
/*

    Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
    
    Sử dụng Disjoin Set, hãy kiểm tra xem đồ thị có tồn tại chu trình hay không?

Input:

    Dòng đầu tiên đưa vào T là số lượng bộ test.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số 
    
    |V|, |E| tương ứng với số đỉnh, số cạnh của đồ thị; 
    
    Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.

    T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

    Đưa ra YES hoặc “NO” kết quả test theo từng dòng 
    
    tương ứng với đồ thị tồn tại hoặc không tồn tại chu trình.

Ví dụ:

Input:                                      Output:

1

6 9

1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6         YES 

*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ii pair<int, int>

vector<int> adj[1005];
int parent[1005], sz[1005];
int n, m;
void init()
{
    for (int i = 1; i <= 1000; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}
int Find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = Find(parent[u]);
}

// True : nếu có thể nối giữa 2 đỉnh
// False: 2 đỉnh đã cùng parent

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return false;
    if (sz[x] < sz[y])
    {
        sz[y] += sz[x];
        parent[x] = y;
    }
    else
    {
        sz[x] += sz[y];
        parent[y] = x;
    }
    return true;
}

void solve()
{
    cin >> n >> m;
    bool flag = false;
    init();
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (!Union(x, y))
        {
            flag = true;
        }
    }
    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";
    for (int i = 1; i <= n; i++)
    {
        parent[i] = sz[i] = 0;
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