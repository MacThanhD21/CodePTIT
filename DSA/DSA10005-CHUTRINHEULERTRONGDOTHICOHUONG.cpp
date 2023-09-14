

/*

    Cho đồ thị có hướng liên thông yếu G=<V, E> được biểu diễn dưới 
    
    dạng danh sách cạnh. Hãy kiểm tra xem đồ thị có chu trình Euler hay không?

Input:

    Dòng đầu tiên đưa vào T là số lượng bộ test.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số 
    
    |V|, |E| tương ứng với số đỉnh,  số cạnh của đồ thị; 
    
    Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.

    T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

    Đưa ra 1, 0 kết quả mỗi test theo từng dòng tương ứng 
    
    với đồ thị có chu trình Euler và trường hợp không tồn tại đáp án.

Ví dụ:

Input:                                                  Output:

2

6  10  

1 2 2 4 2 5 3 1 3 2 4 3 4 5 5 3 5 6 6 4                 1

3 3

1 2 2 3 1 3                                             0

*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

vector<int> adj[1005], T_adj[1005];
bool used[1005];
int n, m;

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        used[i] = false;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
    }
}
void dfs(int u)
{
    used[u] = true;
    for (auto v : adj[u])
    {
        if (!used[v])
        {
            dfs(v);
        }
    }
}

void solve()
{
    init();

    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            cout << "0\n";
            return;
        }
    }

    // memset(used, false, sizeof(used));

    vector<int> degIn(1005, 0), degOut(1005, 0);
    for (int i = 1; i <= n; i++)
    {
        for (auto x : adj[i])
        {
            degIn[i]++;
            degOut[x]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (degIn[i] != degOut[i])
        {
            cout << "0\n";
            return;
        }
    }
    cout << "1\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int TEST = 1;
    cin >> TEST;
    for (int test = 1; test <= TEST; test++)
    {
        solve();
    }
}