
/*

    Cho số tự nhiên n. Hãy in ra tất cả các số nhị phân từ 1 đến n.

Input:

    Dòng đầu tiên ghi lại số lượng test T (T≤100).

    Mỗi test là một số tự nhiên n được ghi

    trên một dòng (n≤10000).
Output:

    Đưa ra kết quả mỗi test trên một dòng.
Ví dụ:

Input               Output

2

2                   1 10

5                   1 10 11 100 101

*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, b) for (int i = 0; i < b; i++)
#define PER(i, b) for (int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;
const int LOG = 12;

void solve()
{
    int n;
    cin >> n;
    queue<ll> Q;
    Q.push(1);

    vector<ll> bin;
    while (1)
    {
        auto top = Q.front();
        Q.pop();
        bin.push_back(top);
        if (bin.size() == n)
            break;

        Q.push(top * 10);
        Q.push(top * 10 + 1);
    }
    for (auto x : bin)
        cout << x << " ";
    cout << "\n";
}
int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}