
/*

    Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự.

    Hãy tìm xâu con đối xứng dài nhất của S.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

    Mỗi test gồm một xâu S có độ dài không vượt quá 1000, 
    
    chỉ gồm các kí tự thường.

Output:  

    Với mỗi test, in ra đáp án tìm được.

Ví dụ:

Input           Output

2

abcbadd         5

aaaaa           5

*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        bool dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
        }

        // duyet theo chiều dài của xâu
        // duyệt từ chỉ số đầu tiên của mỗi xâu con
        // tính chỉ số kết thúc mỗi xâu
        // xử lý trong trường hợp xâu chỉ có 2 ký tự
        int ans = 1;
        for (int len = 1; len <= n; len++)
        {
            // len là chiều dài của từng xâu
            for (int i = 0; i <= n - len; i++)
            {
                // Cong thuc tính chỉ số cuối cùng của xâu con
                int j = len + i - 1;
                if (len == 2)
                {
                    if (s[i] == s[j])
                        dp[i][j] = true;
                }

                else
                {
                    // xet cac xau co chieu dai > 2
                    if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                if (dp[i][j])
                {
                    ans = max(ans, len);
                }
            }
        }
        cout << ans << "\n";
    }
}