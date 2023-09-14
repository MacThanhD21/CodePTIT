
/*

    Cho N cột, mỗi cột có chiều cao bằng H[i]. 

    Bạn hãy tìm hình chữ nhật lớn nhất bị che phủ bởi các cột?

    C:\Users\ADMIN\Downloads\download.png

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test bắt đầu bởi số nguyên N (N ≤ 100 000).

    Dòng tiếp theo gồm N số nguyên H[i] (1 ≤ H[i] ≤ 109).

Output: 

    Với mỗi test, in ra diện tích hình chữ nhật lớn nhất tìm được.

Ví dụ:

Input                   Output

2

7

6 2 5 4 5 1 6           12

3

2 2 2                   6
*/

#include "bits/stdc++.h"

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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 166
#define debugArr(...) 166
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;
const int LOG = 12;

void solve()
{
    int n;
    cin >> n;
    ll a[n];
    for (ll &x : a)
        cin >> x;
    stack<int> st;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[i] < a[st.top()])
        {
            int x = st.top();
            st.pop();
            if (st.empty())
            {
                ans = max(ans, i * a[x]);
            }
            else
            {
                ans = max(ans, (i - st.top() - 1) * a[x]);
            }
        }
        st.push(i);
    }
    while (st.size())
    {
        int x = st.top();
        st.pop();
        if (st.empty())
        {
            ans = max(ans, n * a[x]);
        }
        else
        {
            ans = max(ans, (n - st.top() - 1) * a[x]);
        }
    }
    cout << ans << "\n";
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int TEST = 1;
    cin >> TEST;
    for (int test = 1; test <= TEST; test++)
    {
        solve();
    }
}