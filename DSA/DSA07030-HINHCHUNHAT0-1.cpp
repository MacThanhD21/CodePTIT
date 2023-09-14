
/*

    Cho một bảng kích thước NxM, được chia thành lưới ô vuông đơn vị

    N dòng M cột. Trên các ô của bảng ghi số 0 hoặc 1. Các dòng của bảng

    được đánh số 1, 2... N theo thứ tự từ trên xuống dưới và các cột

    của bảng được đánh số 1, 2..., M theo thứ tự từ trái qua phải

    Yêu cầu: Hãy tìm một hình chữ nhật gồm các ô của bảng thoả mãn các điều kiện sau:

    1 - Hình chữ nhật đó chỉ gồm các số 1

    2 - Cạnh hình chữ nhật song song với cạnh bảng

    3 - Diện tích hình chữ nhật là lớn nhất có thể

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test bắt đầu bởi hai số nguyên N và M (1 ≤ M, N ≤ 500).

    N dòng tiếp theo, mỗi dòng gồm M số nguyên 0 hoặc 1.

Output:

    Với mỗi test, in ra diện tích hình chữ nhật lớn nhất tìm được.

Ví dụ:

Input                                   Output

1

11 13

0 0 0 0 0 1 0 0 0 0 0 0 0

0 0 0 0 1 1 1 0 0 0 0 0 0

0 0 1 1 1 1 1 1 1 0 0 0 0

0 0 1 1 1 1 1 1 1 0 0 0 0

0 1 1 1 1 1 1 1 1 1 0 0 0

1 1 1 1 1 1 1 1 1 1 1 0 0               49

0 1 1 1 1 1 1 1 1 1 0 0 0

0 0 1 1 1 1 1 1 1 0 0 0 0

0 0 1 1 1 1 1 1 1 0 0 0 0

0 0 0 0 1 1 1 0 0 0 0 1 1

0 0 0 0 0 1 0 0 0 0 0 1 1

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

inline int calc(vector<int> a, int n)
{
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[i] < a[st.top()])
        {
            auto top = st.top();
            st.pop();
            if (st.size() == 0)
            {
                ans = max(ans, (i)*a[top]);
            }
            else
            {
                ans = max(ans, (i - st.top() - 1) * a[top]);
            }
            // cout << ans << "\n";
        }
        st.push(i);
    }
    while (st.size())
    {
        auto top = st.top();
        st.pop();
        if (st.size() == 0)
        {
            ans = max(ans, (n)*a[top]);
        }
        else
        {
            ans = max(ans, (n - st.top() - 1) * a[top]);
        }
    }
    return ans;
}
inline void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int preFix_2D[n][m];
    vector<int> row[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
                preFix_2D[i][j] = a[i][j];
            else if (a[i][j])
            {
                preFix_2D[i][j] = preFix_2D[i - 1][j] + a[i][j];
            }
            else
            {
                preFix_2D[i][j] = 0;
            }
            row[i].push_back(preFix_2D[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, calc(row[i], m));
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