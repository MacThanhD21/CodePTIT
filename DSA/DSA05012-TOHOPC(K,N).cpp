/*

    Cho 2 số nguyên n, k. Bạn hãy tính C(n, k) modulo 109+7.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm 2 số nguyên n, k (1 ≤ k ≤ n ≤ 1000).
Output: 

    Với mỗi test, in ra đáp án trên một dòng.
Ví dụ:

Input           Output

2

5 2             10

10 3            20

*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[1005][1005];
const int mod = 1e9 + 7;

void Cnk()
{
    memset(a, 0, sizeof(a));
    cin >> n >> k;
    a[0][0] = 1;
    a[1][0] = a[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                a[i][j] = 1;
            else
            {
                a[i][j] = ((a[i - 1][j - 1] % mod) + (a[i - 1][j] % mod)) % mod;
            }
        }
    }
    cout << a[n][k] % mod << "\n";
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= i; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        Cnk();
    }
}