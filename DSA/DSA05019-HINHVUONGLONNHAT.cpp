
/*

    Cho một bảng số N hàng, M cột chỉ gồm 0 và 1.
    
     Bạn hãy tìm hình vuông có kích thước lớn nhất, 
     
     sao cho các số trong hình vuông toàn là số 1.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

    Mỗi test bắt đầu bởi 2 số nguyên N, M (1 ≤ N, M ≤ 500).

    N dòng tiếp theo, mỗi dòng gồm M số mô tả một hàng của bảng.

Output: 

    Với mỗi test, in ra đáp án là kích thước của hình vuông lớn nhất tìm được trên một dòng.
Ví dụ:

Input                   Output

2

6 5

0 1 1 0 1

1 1 0 1 0

0 1 1 1 0               3

1 1 1 1 0

1 1 1 1 1

0 0 0 0 0

2 2

0 0                     0

0 0

*/

#include <bits/stdc++.h>

using namespace std;
const int N = 505;

int n, m;
int dp[N][N];
int a[N][N];

void solve()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    memset(dp, 0, sizeof(dp));

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j])
            {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans << "\n";
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}