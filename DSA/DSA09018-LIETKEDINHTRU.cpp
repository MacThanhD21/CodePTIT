

/*


    Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn dưới 
    
    dạng danh sách cạnh. Hãy đưa ra tất cả các đỉnh trụ của đồ thị?

Input:

    Dòng đầu tiên đưa vào T là số lượng bộ test.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số 
    
    |V|, |E| tương ứng với số đỉnh và số cạnh; 
    
    Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV 
    
    tương ứng với một cạnh của đồ thị.

    T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

    Đưa ra danh sách các đỉnh trụ của mỗi test  theo từng dòng.
Ví dụ:

Input:                          Output:

1

5 5

1 2 1 3 2 3 2 5 3 4             2 3

*/


#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long

const int N = 1005;

int n, m, timer = 1;
vector<int> adj[N];
int disc[N], low[N];
bool visited[N];
bool AP[N];
set<int> ans;

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
}

void dfsTru(int u, int par)
{
    low[u] = disc[u] = timer++;
    int dem = 0; // Đếm xem đỉnh u có bao nhiêu con
    // duyệt các đỉnh kề với đỉnh u
    for (auto v : adj[u])
    {
        if (v == par)
        {
            continue;
        }
        if (disc[v] == 0)
        {
            ++dem;
            dfsTru(v, u);
            // sau khi dfs trên chạy xong, cập nhật low[u]
            low[u] = min(low[u], low[v]);
            // kiểm tra đỉnh trụ
            if (low[v] >= disc[u] && par != -1)
            {
                ans.insert(u);
            }
        }
        // đỉnh v đã được thăm
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    // Trường hợp đỉnh đầu có 2 nhánh con thì nó cũng là đỉnh trụ
    if (par == -1 && dem >= 2)
    {
        ans.insert(u);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        nhap();
        for (int i = 1; i <= n; i++)
        {
            if (disc[i] == 0)
            {
                dfsTru(i, -1);
            }
        }
        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            disc[i] = low[i] = 0;
            visited[i] = false;
            AP[i] = 0;
        }
        ans.clear();
    }
}