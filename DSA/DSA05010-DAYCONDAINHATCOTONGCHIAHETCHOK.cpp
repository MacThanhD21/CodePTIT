/*

    Cho một dãy gồm n ( n ≤ 1000) số nguyên dương A1, A2, ..., 
    
    An và số nguyên dương k (k ≤ 50). Hãy tìm dãy con gồm nhiều 
    
    phần tử nhất của dãy đã cho sao cho tổng các phần tử của dãy con này chia hết cho k. 

Input: 

    Dòng đầu ghi số bộ test T (T<10). Mỗi bộ test gồm 2 dòng. Dòng đầu tiên chứa hai số n, k.  Dòng tiếp theo ghi n số của dãy A. Các số đều không vượt quá 100.   

Output: Gồm 1 dòng duy nhất ghi số lượng phần tử của dãy con dài nhất thoả mãn. Dữ liệu vào luôn đảm bảo sẽ có ít nhất một dãy con có tổng chia hết cho k.

Ví dụ:

Input                       Output

1

10 3
2 3 5 7 9 6 12 7 11 15      9

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

#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e4 + 2;

void run_case()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    //
    vector<vector<int>> f(n + 1, vector<int>(k, -1));
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    f[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (f[i - 1][j] != -1)
            {
                // chon
                f[i][(j + a[i]) % k] = max(f[i][(j + a[i]) % k], f[i - 1][j] + 1);
                // ko chon
                f[i][j] = max(f[i][j], f[i - 1][j]);
            }
        }
    }
    cout << f[n][0] << "\n";
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    // for (int i = 0; i <= 10; i++) cout << f[i] << "\n";
    int Test = 1;
    cin >> Test;

    for (int test = 1; test <= Test; test++)
    {
        run_case();
    }
}
