/*

    Cho một bàn cờ 8 x 8, mỗi ô có một giá trị A[i][j] nhất định 

    (0 ≤ A[i][j] ≤ 100), tương ứng với điểm số đạt được nếu như bạn đặt một quân cờ vào đó.

    Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ, 

    sao cho không có 2 quân nào ăn nhau, và số điểm đạt được là lớn nhất.

Input: 
    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm 8 dòng, mỗi dòng 8 số nguyên mô tả bàn cờ.

Output:  

    Với mỗi test, in ra đáp án trên một dòng.

*/

#include <bits/stdc++.h>
using namespace std;

int a[20][20], ans;
bool b[20], c[20], d[20];

void Try(int i, int sum)
{
    for (int j = 1; j <= 8; ++j)
    {
        if (!b[j] && !c[i + j - 1] && !d[i - j + 8])
        {
            b[j] = c[i + j - 1] = d[i - j + 8] = true;
            sum += a[i][j];
            if (i == 8)
                ans = max(ans, sum);
            else
                Try(i + 1, sum);
            sum -= a[i][j];
            b[j] = c[i + j - 1] = d[i - j + 8] = false;
        }
    }
}

void testCase()
{
    ans = 0;
    for (int i = 1; i <= 8; ++i)
    {
        for (int j = 1; j <= 8; ++j)
        {
            cin >> a[i][j];
        }
    }
    Try(1, 0);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        testCase();
        cout << "\n";
    }
    return 0;
}