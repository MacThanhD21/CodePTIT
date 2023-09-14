/*

    Cho dãy số nguyên A[] gồm có N phần tử. Nhiệm vụ của bạn là tìm dãy số

    B[] có tổng phần tử nhỏ nhất thỏa mãn tính chất A[i] / B[i] = A[i+1] / B[i+1]

    với mọi chỉ số i (0 ≤ i ≤ N-2).

    Phép chia trong bài toán này là phép chia nguyên (tức là chỉ lấy phần nguyên

    của kết quả: ví dụ 5/3 = 1).

Dữ liệu vào:

    Dòng đầu tiên là số lượng phần tử N (1 ≤ N ≤ 1000).

    Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 2000).

Kết quả:

    In ra một số nguyên là tổng các phần tử của dãy số B[] tìm được.

Ví dụ:

Input:              Output:

5                   25

18 27 16 22 6

Giải thích test: Dãy B[] tìm được là 5, 7, 5, 6, 2.
*/

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n, x, minn = 1e9;
    cin >> n;
    int s[2][100000];
    memset(s, 0, sizeof(s));
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        minn = min(x, minn);
        s[0][1]++;
        s[1][1] += x;
        for (int j = 2; j <= x / 2; j++)
        {
            if (x / j != x / (j - 1))
            {
                s[0][x / j]++;
                s[1][x / j] += j;
            }
        }
    }
    for (int i = minn; i > 0; i--)
    {
        if (s[0][i] == n)
        {
            cout << s[1][i];
            break;
        }
    }
}