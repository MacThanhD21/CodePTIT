
/*

    Cho xâu ký tự S. Nhiệm vụ của bạn là tìm số phép loại bỏ 
    
    ít nhất các ký tự trong S để S trở thành xâu đối xứng. 
    
    Chú ý, phép loại bỏ phải bảo toàn tính trước sau của các ký tự trong S.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 

    Mỗi bộ test là một xâu ký tự được viết trên một dòng

    T, str thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤100.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input               Output

2
aebcbda             2
geeksforgeeks       8

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
    string s;
    cin >> s;
    int n = s.size();
    int dp[n + 1][n + 1] = {0};

    // dp[i][j] : luu số ký tự (số cách ít nhất để biến xâu s từ vị trí i => j thành xâu đối xứng).

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = len + i - 1;
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
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