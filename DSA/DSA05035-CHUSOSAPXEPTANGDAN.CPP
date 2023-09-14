

/*

    Xét các số X có các chữ số được sắp xếp tăng dần, tức a[1] ≤ a[2] ≤ … ≤ a[N]

    trong đó a[1], a[2], …, a[N] lần lượt là các chữ số của X. Chẳng hạn 223, 8999, …

    Cho trước số chữ số N. Nhiệm vụ của bạn là đếm xem có bao nhiêu số như vậy.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
    Mỗi test gồm một số nguyên dương N (1 ≤ N ≤ 100).
Output:

    Với mỗi test, in ra đáp án tìm được trên một dòng theo modulo 109+7.
Ví dụ:

Input               Output

3

1                   10

2                   55

3                   220

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <climits>
#include <set>
#define mod 1000000007
#define ll long long
#define p(x) pair<x, x>
#define v(x) vector<x>
#define FORD(i, l, r) for (int i = l; i < r; i++)
#define FORE(i, l, r) for (int i = r - 1; i >= l; i--)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define sz size();
#define all(M) M.begin(), M.end()
#define f first
#define s second
#define pb push_back
#define pf push_font
using namespace std;

ll to_Hop(int n, int k)
{
    ll dp[110][110];
    FORD(i, 0, n + 1)
    {
        FORD(j, 0, k + 1)
        {
            if (i == j || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            dp[i][j] %= mod;
        }
    }
    return dp[n][k];
}

int main()
{
    int t;
    cin >> t;
    ll dp[101];
    dp[1] = 10;
    FORD(i, 2, 101)
    dp[i] = dp[i - 1] % mod + to_Hop(8 + i, i) % mod,
    dp[i] %= mod;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}