
/*

    Cho bảng A[] kích thước N x M (N hàng, M cột). Bạn được phép đi xuống dưới, đi sang phải và đi xuống ô chéo dưới. Khi đi qua ô (i, j), điểm nhận được bằng A[i][j].

    Hãy tìm đường đi từ ô (1, 1) tới ô (N, M) sao cho tổng điểm là nhỏ nhất.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm số nguyên dương N và M.

    N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j] (0 ≤ A[i] ≤ 1000).

Output: 


    Với mỗi test, in ra độ dài dãy con tăng dài nhất trên một dòng.

Ví dụ:

Input               Output

1

3 3                 8

1 2 3

4 8 2

1 5 3

*/

#include <bits/stdc++.h>

using namespace std;
const int N = 505;

#define ll long long

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    int dp[n + 1][m + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = 1e9;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + a[i][j];
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    // cout << dp[n][m] << "\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}