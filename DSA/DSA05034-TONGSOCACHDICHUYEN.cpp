

/*

    Khu vui chơi trẻ em thiết kế một cầu thang có N bậc để di chuyển lên đỉnh tháp. 
    
    Sinh viên PTIT cũng được phép leo lên cầu thang này nhưng nhìn chung chân sinh viên 
    
    PTIT khá là dài nên có thể đi từ 1 đến K bậc mỗi bước (chứ không chỉ là 1 bậc như trẻ em).

    Hãy tính xem sinh viên PTIT có bao nhiêu cách để leo lên đến đỉnh.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 100).

    Mỗi test gồm hai số nguyên dương N và K (1 ≤ N ≤ 100000, 1 ≤ K ≤ 100).

Output: 

    Với mỗi test, in ra đáp án tìm được 
    
    trên một dòng theo modulo 109+7.

Ví dụ:

Input               Output

2

2 2                 2

4 2                 5

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
// int a[N][N];
int n, k;

void SumTravel()
{
    cin >> n >> k;
    int dp[n + 1] = {0};
    dp[0] = 1, dp[1] = 1;
    // Xay dung số cách bước từ bậc thứ 2
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i >= j)
            {
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t --> 0)
    {
        SumTravel();
    }
}