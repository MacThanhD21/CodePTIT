

/*

    Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn 
    
    dưới dạng danh sách cạnh. Hãy đưa ra tất cả các cạnh cầu của đồ thị?

Input:

    Dòng đầu tiên đưa vào T là số lượng bộ test.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm |E| + 1 dòng: dòng đầu tiên đưa vào hai số 
    
    |V|, |E| tương ứng với số đỉnh và số cạnh; |E| dòng tiếp theo 
    
    đưa vào các bộ đôi u, v tương ứng với một cạnh của đồ thị.

    T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

    Đưa ra danh sách các cạch cầu của mỗi test theo từng dòng. 
    
    In ra đáp án theo thứ tự từ điển, theo dạng “a b …” với a < b.

Ví dụ:

Input:              Output:

1

5 5

1 2 

1 3                 2 5 3 4

2 3

2 5

3 4

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pb push_back
#define ms(a) memset(a, 0, sizeof(a));

const int MAX = 1500;

vector<int> adj[MAX];
int disc[MAX], low[MAX];

int timer = 1;

vector<pair<int, int>> bridge;

void tarJan(int u, int par)
{
    disc[u] = low[u] = timer++;
    for (auto v : adj[u])
    {
        if (v == par)
            continue;

        if (disc[v] == 0)
        {
            tarJan(v, u);
            // update low cho dinh u
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
            {
                bridge.pb({min(u, v), max(u, v)});
            }
        }
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void solve()
{

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    tarJan(1, -1);
    sort(bridge.begin(), bridge.end());
    for (auto x : bridge)
    {
        cout << x.first << " " << x.second << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        disc[i] = low[i] = 0;
    }
    timer = 1;
    bridge.clear();
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