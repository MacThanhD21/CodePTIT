
/*

    Dãy số Fibonacci được xác định bằng công thức như sau:

    F[0] = 0, F[1] = 1;

    F[n] = F[n-1] + F[n-2] với mọi n >= 2.

    Các phần tử đầu tiên của dãy số là 0, 1, 1, 2, 3, 5, 8, ...

    Nhiệm vụ của bạn là hãy xác định số Fibonaci thứ n. 
    
    Do đáp số có thể rất lớn, in ra kết quả theo modulo 109+7.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 1000).

    Mỗi test bắt gồm một số nguyên N (1 ≤ N ≤ 109).

Output: 

    Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input             Output

3

2                 1

6                 8

20                6765

*/


#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = (int)1e9 + 7;

// Su dung phuong phap nhan ma tran
struct matrix
{
    ll a[2][2];

    matrix operator*(matrix khac)
    {
        matrix res;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                res.a[i][j] = 0;
                for (int k = 0; k < 2; k++)
                {
                    res.a[i][j] += a[i][k] * khac.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

matrix powMod(matrix a, ll n)
{
    if (n == 1)
        return a;
    matrix tmp = powMod(a, n / 2);
    if (n % 2 == 1)
    {
        return tmp * tmp * a;
    }
    else
    {
        return tmp * tmp;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        matrix res;
        res.a[0][0] = 1; res.a[1][0] = 1; // 1 1 
        res.a[0][1] = 1; res.a[1][1] = 0; // 1 0
        matrix ans = powMod(res, n);
        cout << ans.a[0][1] << "\n"; // so fibo thu n
    }
}


/*


mod = int(1e9 + 7)

class Matrix:
    def __init__(self, a):
        self.a = a

    def __mul__(self, other):
        res = [[0, 0], [0, 0]]
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    res[i][j] += (self.a[i][k] * other.a[k][j]) % mod
                    res[i][j] %= mod
        return Matrix(res)


def powMod(a, n):
    if n == 1:
        return a
    tmp = powMod(a, n // 2)
    if n % 2 == 1:
        return tmp * tmp * a
    else:
        return tmp * tmp


t = int(input())
for _ in range(t):
    n = int(input())
    res = Matrix([[1, 1], [1, 0]])
    ans = powMod(res, n)
    print(ans.a[0][1])

*/