
/*


    Cho hai dãy số thực A[] và B[] đều có N phần tử, các giá trị 
    
    là số thực và không quá 100.

    Hãy tính độ dài dài nhất của dãy các vị trí (không cần liên tiếp) 
    
    thỏa mãn cả hai điều kiện:

    Nếu xét các vị trí đó trên dãy A[] thì dãy con thu được thỏa mãn 
    
    tính chất tăng dần (giá trị bằng nhau không được tính vào dãy tăng).

    Nếu xét các vị trí đó trên dãy B[] thì dãy con thu được thỏa mãn 
    
    tính chất giảm dần (giá trị bằng nhau không được tính vào dãy giảm).

Input

    Dòng đầu ghi số bộ test (không quá 100).

    Mỗi bộ test bắt đầu bởi số N (không quá 500).

    Tiếp theo là N dòng, mỗi dòng ghi 2 giá trị A[i] và B[i]

Output

    Với mỗi test, ghi ra độ dài tính được trên một dòng.

Ví dụ

Input                   Output

3

2

1.0 1.0                 2

1.5 0.0

3

1.0 1.0

1.0 1.0                 1

1.0 1.0

6

1.5 9.0

2.0 2.0

2.5 6.0                 4

3.0 5.0

4.0 2.0

10.0 5.5

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
    float u[n], v[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> u[i] >> v[i];
    }
    vector<int> dp(n + 1, 1);
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (u[j] < u[i] && v[j] > v[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
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

