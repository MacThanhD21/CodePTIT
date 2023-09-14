
/*

    Cho đồ thị vô hướng có N đỉnh và M cạnh.

    Bạn hãy tìm đường đi dài nhất trên đồ thị,

    sao cho mỗi cạnh chỉ được đi qua nhiều nhất 1 lần.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

    Mỗi test bắt đầu bằng số nguyên N và M (1 ≤ N, M ≤ 20).

    Các đỉnh đánh dấu từ 0, 1, …, N-1. M dòng tiếp theo,

    mỗi dòng gồm 2 số u, v cho biết có cạnh nối giữa uàv.

Output:

    Với mỗi test, in ra đáp án tìm được,

    mỗi xâu in ra trên một dòng.

Ví dụ

Input               Output

2

3 2

0 1

1 2

15 16

0 2                 2

1 2

2 3

3 4

3 5

4 6

5 7                 12

6 8

7 8

7 9

8 10

9 11

10 12

11 12

10 13

12 14

*/


#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, res;
vector<vector<int>> G;
bool vs[20][20] = {};

void dfs(int u, int len)
{
    res = max(res, len);
    for (int v : G[u])
    {
        if (!vs[u][v])
        {
            vs[u][v] = vs[v][u] = true;
            dfs(v, len + 1);
            vs[u][v] = vs[v][u] = false;
        }
    }
}

void testCase()
{
    res = 0;
    cin >> n >> m;
    G.clear();
    G.resize(20);
    while (m--)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < n; ++i)
    {
        dfs(i, 0);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        testCase();
        cout << "\n";
    }
    return 0;
}