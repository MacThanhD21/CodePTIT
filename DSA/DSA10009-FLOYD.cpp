

/*

    Cho đơn đồ thị vô hướng liên thông G = (V, E) gồm N đỉnh và M cạnh, 
    
    các đỉnh được đánh số từ 1 tới N và các cạnh được đánh số từ 1 tới M.

    Có Q truy vấn, mỗi truy vấn yêu cầu bạn tìm đường đi ngắn nhất giữa đỉnh X[i] tới Y[i].

Input:

    Dòng đầu tiên hai số nguyên N và M (1 ≤ N ≤ 100, 1 ≤ M ≤ N*(N-1)/2).

    M dòng tiếp theo, mỗi dòng gồm 3 số nguyên u, v, c 
    
    cho biết có cạnh nối giữa đỉnh u và v có độ dài bằng c (1 ≤ c ≤ 1000).

    Tiếp theo là số lượng truy vấn Q (1 ≤ Q ≤ 100 000).

    Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên X[i], Y[i].

Output: 

    Với mỗi truy vấn, in ra đáp án là độ dài đường đi ngắn nhất tìm được.

Ví dụ:

Input               Output

5 6

1 2 6               8

1 3 7               10

2 4 8               3

3 4 9

3 5 1

4 5 2

3

1 5

2 5

4 3


*/


#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<int, int>
#define v vector
#define pb push_back

int n, m;
int dist[105][105];

void solution()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = w;
    }
    // 3 For
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int query;
    cin >> query;
    while (query--)
    {
        int u, v;
        cin >> u >> v;
        cout << dist[u][v] << "\n";
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solution();
}