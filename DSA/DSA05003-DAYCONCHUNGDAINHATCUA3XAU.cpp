/*
 Cho ba xâu ký tự X, Y, Z. Nhiệm vụ của bạn là tìm độ dài dãy con chung 
 
 dài nhất có mặt trong cả ba xâu.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào độ dài xâu X, Y, X;
    
    dòng tiếp theo đưa vào ba xâu X, Y, Z.

    T, X, Y, Z thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ size(X), size(Y), size(Z) ≤ 100.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input                               Output

2

5 8 13
geeks geeksfor geeksforgeeks        5

7 6 5
abcd1e2 bc12ea bd1ea                3
 */

#include <bits/stdc++.h>
#include <string>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define is insert
#define fi first
#define se second

const int mod = 1e9 + 7;
const int maxx = 1e7 + 5;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string a, b, c;
    cin >> a >> b >> c;
    int dp[n + 1][m + 1][k + 1];

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int h = 1; h <= k; h++)
            {
                if (a[i - 1] == b[j - 1] && a[i - 1] == c[h - 1])
                {
                    dp[i][j][h] = dp[i - 1][j - 1][h - 1] + 1;
                }
                else
                {
                    dp[i][j][h] = max({dp[i - 1][j][h], dp[i][j - 1][h], dp[i][j][h - 1]});
                }
            }
        }
    }
    cout << dp[n][m][k] << "\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}