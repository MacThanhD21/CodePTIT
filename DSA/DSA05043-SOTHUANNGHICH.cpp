
/*

    Cho số nguyên dương N có không quá 1000 chữ số. Hãy tính độ dài 
    
    lớn nhất của một số thuận nghịch tạo được bằng cách lấy liên tiếp 
    
    các chữ số trong N.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

    Mỗi test ghi ra một số nguyên dương N không quá 1000 chữ số.

Output:  

    Với mỗi test, in ra đáp án tìm được.

Ví dụ:

Input               Output

2

13731456            5

44444               5

*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    int dp[n + 1][n + 1] = {0};
    for (int i = 0; i <= n; i++)
    {
        dp[i][i] = 1;
    }
    int ans = 0;
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = len + i - 1;
            if (len == 2)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 1;
                }
            }
            else
            {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
            if (dp[i][j])
            {
                ans = max(ans, len);
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}