/*

    Cho 2 xâu S1 và S2. Hãy tìm xâu con chung dài nhất của 2 xâu này

    (các phần tử không nhất thiết phải liên tiếp nhau).

Input:
    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm hai dòng, mô tả xâu S1 và S2,

    mỗi xâu có độ dài không quá 1000 và chỉ gồm các chữ cái in hoa.

Output:

    Với mỗi test, in ra độ dài dãy con chung dài nhất trên một dòng.

Ví dụ:

Input               Output

2

AGGTAB              4
GXTXAYB

AA                  0
BB

*/
/*------------------------Cach 1---------------------*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        int dp[n + 1][m + 1];
        ms(dp);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        cout << dp[n][m] << "\n";
    }
}

/*------------------------Cach 2---------------------*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s1, s2;
int n, m;
int dp[1005][1005];

int back(int i, int j)
{
    if (i == -1 || j == -1)
        return 0;
    if (s1[i] == s2[j])
        return 1 + back(i - 1, j - 1);
    int x = 0, y = 0;
    if (i - 1 >= 0 && dp[i - 1][j] != -1)
        x = dp[i - 1][j];
    else
        x = back(i - 1, j);
    if (j - 1 >= 0 && dp[i][j - 1] != -1)
        y = dp[i][j - 1];
    else
        y = back(i, j - 1);
    dp[i][j] = max(x, y);
    return max(x, y);
}

void solve()
{
    cin >> s1 >> s2;
    n = s1.size(), m = s2.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            dp[i][j] = -1;
    }
    cout << back(n - 1, m - 1) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}