
/*

    Một con ếch có thể nhảy 1, 2, 3 bước để có thể lên đến một đỉnh cần đến.

    Hãy đếm số các cách con ếch có thể nhảy đến đỉnh.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test.

    Mỗi bộ test là số n là số bước con ếch có thể lên được đỉnh.

    T, n thỏa mãn ràng buộc: 1≤T≤100;  1≤n ≤50.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input           Output

2
1               1
5               13

*/


// CACH 1
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

void Frog()
{
    int n;
    cin >> n;
    ll dp[n + 1] = {0};
    dp[0] = 1;;
    // Xay dung số cách bước từ bậc thứ 2
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (i >= j)
            {
                dp[i] += dp[i - j];
            }
        }
    }
    cout << dp[n] << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t --> 0)
    {
        Frog();
    }
}

// CACH 2

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll dp[100005];
int n;

ll back(int n)
{
    if (dp[n] != -1)
        return dp[n];
    ll ans = 0;
    for (int i = 1; i <= 3; i++)
    {
        int tmp = n - i;
        if (tmp >= 0)
        {
            if (dp[tmp] == -1)
                ans += back(tmp);
            else
                ans += dp[tmp];
        }
    }
    dp[n] = ans;
    return ans;
}
void solve()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
        dp[i] = -1;
    dp[0] = 1;
    cout << back(n) << endl;
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