
/*

    Cho N điểm trên mặt phẳng Oxy. Để vẽ được đoạn thẳng nối A và B sẽ

    tốn chi phí tương đương với khoảng cách từ A tới B.

    Nhiệm vụ của bạn là nối các điểm với nhau, sao cho N điểm đã

    cho tạo thành 1 thành phần liên thông duy nhất và chi phí để

    thực hiện là nhỏ nhất có thể.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test bắt đầu bởi số nguyên N (1 ≤ N ≤ 100).

    N dòng tiếp theo, mỗi dòng gồm 2 số thực x[i], y[i]

    là tọa độ của điểm thứ i (|x[i]|, |y[i]| ≤ 100).
Output:

    Với mỗi test, in ra chi phí nhỏ nhất tìm được với

    độ chính xác 6 chữ số thập phân sau dấu phẩy.

Ví dụ:

Input               Output

1

3                   3.414214

1.0 1.0

2.0 2.0

2.0 4.0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <math.h>

using namespace std;

#define ii pair<double, double>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define ll long long
#define db double

// Kruskal()
struct edge
{
    int u, v;
    double w;
};

vector<edge> adj;
int n, par[105], sz[105];

inline int Find(int u)
{
    if (u == par[u])
        return u;
    return par[u] = Find(par[u]);
}

inline bool Merge(int x, int y)
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

inline bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

inline void Krus()
{
    double ans = 0;
    sort(all(adj), cmp);
    vector<edge> MST;

    for (auto x : adj)
    {
        if (MST.size() == n - 1)
            break;

        int u = x.u, v = x.v;
        double w = x.w;
        if (Merge(u, v))
        {
            ans += w;
            MST.push_back(x);
        }
    }
    printf("%.6f\n", ans);
}

inline void solve()
{
    cin >> n;
    ii a[n + 5];
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
    adj.clear();
    for (int i = 1; i <= n; i++)
    {
        double x, y;
        cin >> x >> y;
        a[i].fi = x;
        a[i].se = y;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double x = abs(a[i].fi - a[j].fi);
            double y = abs(a[i].se - a[j].se);
            double w = sqrt(x * x + y * y);
            edge tmp = {i, j, w};
            adj.push_back(tmp);
        }
    }
    Krus();
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}