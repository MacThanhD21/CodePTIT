

/*

  Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8.

  Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.

Input:

    Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);

    T dòng kế tiếp mỗi dòng ghi số N (1<N<15).
Output:

    Dòng đầu tiên là số lượng số lộc phát tìm được.

    Dòng thứ hai in đáp án theo thứ tự tăng dần.
Ví dụ:

Input           Output

2

2               6

                6 8 66 68 86 88

3               14

                6 8 66 68 86 88 666 668 686 688 866 868 886 888

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
    queue<string> Q;
    Q.push("6");
    Q.push("8");

    set<ll> se;

    while (Q.size())
    {
        auto top = Q.front();
        Q.pop();

        if (top.size() > n)
            break;
        se.insert(stoll(top));

        Q.push(top + "6");
        Q.push(top + "8");
    }
    cout << se.size() << "\n";
    for (auto x : se)
    {
        cout << x << " ";
    }
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