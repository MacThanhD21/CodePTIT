

/*

    Một người có cái túi thể tích V (V<1000). Anh ta có N đồ vật cần mang theo

    (N≤1000), mỗi đồ vật có thể tích là A[i] (A[i]≤100) và giá trị là C[i] (C[i]≤100).

    Hãy xác định tổng giá trị lớn nhất của các đồ vật mà người đó có thể mang theo,

    sao cho tổng thể tích không vượt quá V.

Input

    Dòng đầu ghi số bộ test T (T<10)

    Mỗi bộ test gồm ba dòng. Dòng đầu ghi 2 số N và V.

    Dòng tiếp theo ghi N số của mảng A.

    Sau đó là một dòng ghi N số của mảng C.

    Dữ liệu vào luôn đảm bảo không có đồ vật nào có thể tích lớn hơn V.

Output

    Với mỗi bộ test, ghi trên một dòng

    giá trị lớn nhất có thể đạt được.
Ví dụ

Input                                       Output

1

15 10                                       15

5 2 1 3 5 2 5 8 9 6 3 1 4 7 8

1 2 3 5 1 2 5 8 7 4 1 2 3 2 1

*/

// CACH 1
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

void KnapSack()
{
    int n, S;
    cin >> n >> S;
    int a[n], w[n];

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    int dp[n + 1][S + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= S; j++)
        {
            // Khong chon do vat nao
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + w[i]);
            }
        }
    }
    cout << dp[n][S] << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        KnapSack();
    }
}
// CACH 2
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[100005], c[100005];
struct sv
{
    int w, v;
};
sv dp[1005];
void solve()
{
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i <= b; i++)
        dp[i].w = 0, dp[i].v = 0;
    dp[0].w = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = b; j >= 0; j--)
        {
            if (j - a[i] >= 0 && dp[j - a[i]].w)
                dp[j].v = max(dp[j].v, dp[j - a[i]].v + c[i]), dp[j].w = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= b; i++)
        ans = max(ans, dp[i].v);
    cout << ans << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
// CACH 3
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n, v;
    cin >> n >> v;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].first;
    for (int i = 0; i < n; i++)
        cin >> a[i].second;
    pair<bool, int> dp[v + 1];
    for (int i = 0; i <= v; i++)
        dp[i].first = false, dp[i].second = 0;
    dp[0].first = true;
    for (int i = 0; i < n; i++)
    { // first = khoi luong , second = gia tri
        int w = a[i].first, value = a[i].second;
        for (int j = v; j >= a[i].first; j--)
        {
            if (dp[j - w].first)
                dp[j].second = max(dp[j].second, dp[j - w].second + value), dp[j].first = true;
        }
    }
    cout << dp[v].second << endl;
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