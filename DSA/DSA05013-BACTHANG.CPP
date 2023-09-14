
/*

    Một chiếc cầu thang có N bậc. Mỗi bước, bạn được phép bước

    lên trên tối đa K bước. Hỏi có tất cả bao nhiêu cách bước

    để đi hết cầu thang? (Tổng số bước đúng bằng N).

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 100).

    Mỗi test gồm hai số nguyên dương N và K(1 ≤ N ≤ 100000, 1 ≤ K ≤ 100).
Output:

    Với mỗi test, in ra đáp án tìm được trên một dòng theo modulo 109+7.
Ví dụ:

Input           Output

2

2 2             2

4 2             5

Giải thích test 1: Có 2 cách đó là (1, 1) và (2).

Giải thích test 2: 5 cách đó là: (1, 1, 1, 1), (1, 1, 2), (1, 2, 1), (2, 1, 1), (2, 2).

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll mod = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    k = min(k, n);
    ll dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= k; i++)
        dp[i] = dp[i - 1] * 2, dp[i] %= mod;

    for (int i = k + 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] * 2 - dp[i - k - 1];
        dp[i] %= mod;
    }
    cout << (dp[n] + mod) % mod << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
