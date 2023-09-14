

/*

Số Ugly là các số chỉ có ước số là 2, 3, 5. Theo qui ước số 1 cũng là 1 số Ugly.

Dưới đây là 11 số Ugly đầu tiên: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15.

Cho số tự nhiên N, nhiệm vụ của bạn là tìm số Ugly thứ N.

Input:  Dòng đầu tiên đưa vào số lượng bộ test T.  Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng. T, N thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ N ≤ 104.

Output: Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input           Output

2
10              12
4               4

*/

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int dem = 0;
        int a = 0, b = 0, c = 0;
        int dp[10000];
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i] = min(dp[a] * 2, min(dp[b] * 3, dp[c] * 5));
            if (dp[i] == dp[a] * 2)
                a++;
            if (dp[i] == dp[b] * 3)
                b++;
            if (dp[i] == dp[c] * 5)
                c++;
        }
        cout << dp[n - 1] << endl;
    }
}