
/*

    Mọi số nguyên dương N đều có thể phân tích thành tổng các bình phương 
    
    của các số nhỏ hơn N. Ví dụ số 100 = 102 hoặc 100 = 52 + 52 + 52 + 52.
    
     Cho số nguyên dương N. Nhiệm vụ của bạn là tìm số lượng ít nhất các số 
     
     nhỏ hơn N mà có tổng bình phương bằng N.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi test là một số tự nhiên N được viết trên 1 dòng.

    T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤10000.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input               Output

3
100                 1
6                   3
25                  1

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
    int N;
    cin >> N;
    vector<int> dp(N + 1, 1e9);
    dp[0] = 0;
    // dp[i] : lưu số lượng các số nhỏ hơn i mà có tổng bình phương bằng i
    for (int i = 1; i <= N; i++)
    {
        // dp[i] = i;
        for (int j = 1; j <= sqrt(i); j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[N] << "\n";
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