
/*
    Cho dãy số A có N phần tử và số K. Hãy đếm số cách chia dãy A thành K 

    nhóm các phần tử liên tiếp sao cho tổng giá trị của mỗi nhóm đều bằng nhau.

Input

    Dòng đầu ghi hai số N và K (0 < N ≤ 12; 0 < K < N ).

    Dòng thứ 2 ghi N số của dãy A (-10000 ≤ A[i] ≤ 10000)

Output

    In ra số cách thỏa mãn

Ví dụ

Input           Output

3 2

-2 0 -2         2

3 2

1 2 3           1

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

int n, k, sum;
int a[MAX];
int res = 0;

int calc(int L, int R)
{
    int coun = 0;
    for (int i = L; i <= R; i++)
    {
        coun += a[i];
    }
    return coun;
}

void back(int i, int SUM, int cnt)
{
    if (cnt == k && i == n)
    {
        res++;
        return;
    }
    for (int j = i; j <= n; j++)
    {
        if (SUM + a[j] == sum)
        {
            back(j + 1, 0, cnt + 1);
        }
    }
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % k != 0)
    {
        cout << "0\n";
        return;
    }
    else
    {
        sum /= k;
        back(1, 0, 0);
        cout << res << "\n";
    }
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int TEST = 1;
    // cin >> TEST;
    for (int test = 1; test <= TEST; test++)
    {
        solve();
    }
}