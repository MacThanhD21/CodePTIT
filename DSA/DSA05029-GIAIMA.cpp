
/*

    Một bản tin M đã mã hóa bí mật thành các con số theo ánh xạ như sau:
    
    ‘A’->1, ‘B’->2, .., ‘Z’->26. Hãy cho biết có bao nhiêu cách khác nhau 
     
    để giải mã bản tin M. Ví dụ với bản mã M=”123” nó có thể được giải mã 
    
    thành ABC (1 2 3), LC (12 3), AW(1 23).

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test là một xâu ký tự số M.

    T, M thỏa mãn ràng buộc: 1≤T≤100;  1≤length(M)≤40.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input           Output

2
123             3
2563            2

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

int check(string s)
{
    int x = stoi(s);
    if (x >= 10 && x <= 26)
        return 1;
    return 0;
}
void run_case()
{
    string s;
    cin >> s;
    s = "#" + s;
    // cout << s << "\n";
    int n = s.size();
    ll dp[n + 1] = {0};
    for (int i = 0; i <= n; i++)
        dp[i] = 0;
    dp[0] = 1; // Có 1 cách giải mã cho chuỗi rỗng, đó là không giải mã gì cả.

    if (s[1] == '0')
        dp[1] = 0;
    else
        dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        char x = s[i], y = s[i - 1];
        if (check(string(1, y) + string(1, x)))
            dp[i] += dp[i - 2];
        if (s[i] != '0')
            dp[i] += dp[i - 1];
    }
    // for(auto x : dp) cout << x << " ";
    // cout << "\n";
    cout << dp[n] << "\n";
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++)
    {

        run_case();
    }
}