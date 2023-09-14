

/*

    Trong giấc mơ, Tí thấy mình bị lạc trên hòn đảo với cư dân xa lạ. 

    Không biết làm việc gì, Tí đành phải hái dừa đem bán. 

    Tí muốn làm một tấm biến cho quán hàng cửa mình. 

    Lục tung khắp nơi, Tí kiếm được N miếng gỗ hình chữ nhật, 

    mỗi miếng có chiều dài bằng A[i] và chiều rộng bằng 1. 

    Tí đã ghép N miếng gỗ thành một tấm ván lớn, rồi thực hiện 

    cắt các miếng gỗ để thu được tấm biển.

    Tí muốn tấm biển quảng cáo của mình thật đặc biệt, nên Tí 

    đã chọn nhất định nó sẽ là hình vuông. Không có eke, thước, 

    dây, … nên Tí phải dựa vào các miếng gỗ ban đầu để căn nhát cưa. 

    Việc cưa theo chiều dọc rất dễ dàng, nhưng theo chiều ngang, 

    Tí chỉ có thể cưa theo một đường thẳng trùng với một cạnh của miếng gỗ nào đó.

    Các bạn hãy giúp Tí tính thử xem tấm biển quảng cáo của Tí có kích thước 

    lớn nhất bằng bao nhiêu (kích thước ở đây là độ dài cạnh hình vuông).

    C:\Users\ADMIN\Downloads\download (1).jpg

Input: 

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20). 

    Mỗi test bắt đầu bởi số nguyên N (N ≤ 100 000). 

    Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 109).

Output:   

    Với mỗi test, in ra chiều dài cạnh của tấm biển. 

    Nếu Tí không thể tạo thành tấm biển, in ra 0.

Ví dụ:

Input                   Output
4

4

5 2 4 3 3 1 4           3

3

2 2 2                   2

2

6 6                     0

6

5 5 5 5 3 1             3

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
    ll n;
    cin >> n;
    ll a[n];
    for (ll &x : a)
        cin >> x;
    stack<int> st;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        while (!st.empty() && a[i] < a[st.top()])
        {
            int x = st.top();
            st.pop();
            if (st.empty() && i >= a[x])
            {
                ans = max(ans, a[x]);
            }
            else if (!st.empty() && (i - st.top() - 1) >= a[x])
            {
                ans = max(ans, a[x]);
            }
        }
        st.push(i);
    }
    while (st.size())
    {
        int x = st.top();
        st.pop();
        if (st.empty() && n >= a[x])
        {
            ans = max(ans, a[x]);
        }
        else if (!st.empty() && (n - st.top() - 1) >= a[x])
        {
            ans = max(ans, a[x]);
        }
    }
    cout << ans << "\n";
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int TEST;
    cin >> TEST;
    // cout << TEST << "\n";
    for (int test = 1; test <= TEST; test++)
    {
        solve();
    }
}