

/*

    Giả sử bạn đang ở điểm có tọa độ nguyên dương (n,m) và cần dịch

    chuyển về tọa độ (0,0). Mỗi bước dịch chuyển bạn chỉ được phép dịch

    chuyển đến tọa độ (n-1, m) hoặc (n, m-1); Từ ô (0,m), hoặc (n, 0) thì

    có thể di chuyển 1 bước để về gốc (0,0).

    Hãy đếm số cách bạn có thể dịch chuyển về tọa độ (0,0).

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test.

    Mỗi bộ test là bộ n, m được viết cách nhau một vài khoảng trống.

    T, n, m thỏa mãn ràng buộc: 1≤T≤100;  1≤n, m ≤25.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input               Output

3
3 2                 10
3 6                 84
3 0                 1

*/

#include <iostream>
#include <string.h>
#include <stack>

using namespace std;
int m, n;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        long long dp[101][101];
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        }
        cout << (dp[m][n] + 1) / 2 << "\n";
    }
}