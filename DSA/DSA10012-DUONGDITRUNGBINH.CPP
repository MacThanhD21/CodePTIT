

/*

    Cho một đồ thị có hướng gồm N đỉnh và M cạnh. Nhiệm vụ của bạn là hãy tính 

    khoảng cách trung bình ngắn nhất giữa hai node bất kì nếu như chúng liên thông 

    với nhau. Input đảm bảo rằng trong một nhóm liên thông, 

    nếu như u đi tới được v thì v cũng đi tới được v với mọi cặp u, v.

    C:\Users\ADMIN\Downloads\download (6).png

Input:
    Dòng đầu tiên là số lượng bộ test T (T ≤ 20). 
    
    Mỗi test bắt đầu bởi hai số nguyên N và M 
    
    (1 ≤ N ≤ 100, M ≤ N*(N-1)/2). M dòng tiếp theo, 
    
    mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối đơn hướng từ u tới v.

Output:  

    Với mỗi test, in ra đáp án tìm được 
    
    với độ chính xác 2 chữ số sau dấu phảy.

Ví dụ:

Input                   Output

2

4 5                     1.83

1 2

2 4

1 3

3 1

4 3

7 5                     1.75

1 2

1 4

4 2

2 7

7 1

*/

#include <bits/stdc++.h>

using namespace std;

// Floyd
int n, m;
int dp[1005][1005];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        dp[x][y] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    double ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] != 0 && dp[i][j] != 1e9)
            {
                ++cnt;
                ans += (double)dp[i][j];
            }
        }
    }
    cout << fixed << setprecision(2) << ans / cnt << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}