
/*

    Xét các số X có các chữ số được sắp xếp tăng dần,

    tức a[1] ≤ a[2] ≤ … ≤ a[N] trong đó a[1], a[2], …, a[N]

    lần lượt là các chữ số của X. Chẳng hạn 223, 8999, …

    Cho trước số chữ số N. Nhiệm vụ của bạn là đếm xem có

    bao nhiêu số như vậy.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 100).

    Mỗi test gồm một số nguyên dương N (1 ≤ N ≤ 100).

Output:

    Với mỗi test, in ra đáp án tìm được

    trên một dòng theo modulo 109+7.
Ví dụ:

Input           Output

3

1               10

2               55

3               220

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
ll mod = 1e9 + 7;

/**
 * Calculates the sum of all possible numbers that can be formed of length n, 
 * with digits 0-9 and having no two adjacent digits being the same.
 *
 * @param n the length of the number to be formed
 *
 * @return the sum of all possible numbers modulo 10^9+7
 *
 * @throws None
 */
void solve()
{
    int n;
    cin >> n;
    ll dp[n + 1][10];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= mod;
            }
        }
    }
    dp[1][0] = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            ans += dp[i][j];
            ans %= mod;
        }
    }
    cout << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
