
/*

    Cho một cây có N node, gốc tại  1. Độ cao của một node u 
    
    được tính bằng khoảng cách từ u tới node gốc. Độ cao của node 
    
    gốc bằng 0. Nhiệm vụ của bạn là hãy tìm node xa node gốc nhất 
    
    và in ra độ cao của node này.

Input:

    Dòng đầu tiên là số lượng bộ test T( T≤ 20).

    Mỗi test bắt đầu bằng số nguyên N (1 ≤ N ≤ 100 000).

    N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết node u nối với node v.

Output: 

    Với mỗi test, in ra một số nguyên là độ cao của cây.

Ví dụ:

Input                       Output

2

5                           2

1 2

1 3

2 4

2 5

4                           3

1 2

2 3

3 4

*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 5;
bool vs[100001];
vector<int> adj[100001];
int ans = 0;
void dfs(int u, int cnt)
{
    ans = max(ans, cnt);
    vs[u] = true;
    for (auto x : adj[u])
    {
        if (!vs[x])
            dfs(x, cnt + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m = n - 1;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        ans = 0;
        dfs(1, 0);
        cout << ans << "\n";
        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
            vs[i] = false;
        }
    }
}