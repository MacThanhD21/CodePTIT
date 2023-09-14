/*

    Cho 2 số nguyên N và K. Bạn hãy đếm số lượng các số có N chữ số mà 
    
    tổng các chữ số của nó bằng K. Lưu ý, chữ số 0 ở đầu không được chấp nhận.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 50).

    Mỗi test gồm 2 số nguyên N và K (1 ≤ N ≤ 100, 0 ≤ K ≤ 50000).

Output: 

Với mỗi test, in ra đáp số tìm được theo modulo 109+7 trên một dòng.
 

Ví dụ:

Input           Output

3

2 2             2

2 5             5

3 6             21

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

ll calc(ll n){
    ll sum = 0;
    while(n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve()
{
    int n, k; cin >> n >> k;

    int L = pow(10, n - 1);
    int R = pow(10, n);

    vector <ll> dp (k + 1, 0);

    for(int i = 1; i <= k; i++){
        dp[i] = dp[i - 1] + calc(i);
    }
    cout << dp[k] << "\n";
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