
/*

    Cho một mảng A[] gồm N số nguyên và số K. Tính số cách lấy tổng các phần tử của A[] để bằng K. Phép lấy lặp các phần tử hoặc sắp đặt lại các phần tử được chấp thuận. Ví dụ với mảng A[] = {1, 5, 6}, K = 7 ta có 6 cách sau:

    7 = 1 + 1 + 1+1 + 1 + 1+1 (lặp số 1 7 lần)

    7 = 1 + 1 + 5 (lặp số 1)

    7 = 1 + 5 + 1 (lặp và sắp đặt lại số 1)

    7 = 1 + 6

    7 = 6 + 1

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào N và K; 
    
    dòng tiếp theo đưa vào N số của mảng A[]; 
    
    các số được viết cách nhau một vài khoảng trống.

    T, N, K, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤1000; 1≤A[i]≤100.

Output:

    Đưa ra kết quả mỗi test theo từng dòng. 
    
    Khi kết quả quá lớn đưa ra kết quả dưới dạng modulo với 109+7.
Ví dụ:

Input               Output

2
3 7
1 5 6               6

4 14
12 3 1 9            150

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
const int MOD = (int)1e9 + 7;
const int MAX = 1e3 + 5;
const int LOG = 12;

void run_case()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), dp(k + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    dp[0] = 1; // có 1 cách để tạo ra tổng 0 bằng cách không chọn phần tử nào.
    // dp[i] : số cách để tạo ra tổng i

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= a[j])
            {
                dp[i] += dp[i - a[j]];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[k] << "\n";
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