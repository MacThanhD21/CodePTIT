
/*

    Dãy số Tribonacci được xây dựng như sau:

    T(i) = i với i ≤ 3.

    T(i) = T(i-1) + T(i-2) + T(i-3) với i ≥ 4.

    Nhiệm vụ của bạn là hãy tính tổng N phần tử đầu tiên của dãy số này.

    F(N) = T(1) + T(2) + …+ T(N)

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 100).

    Mỗi test gồm một số nguyên dương N (N ≤ 109).

Output:

    Với mỗi test, in ra đáp án tìm được theo modulo 1015+7.

Ví dụ:

Input           Output

5

1               1

2               3

3               6

4               12

5               23

*/

#include <iostream>

using namespace std;

typedef long long ll;
ll MOD = 1000000000000007;

ll M[5] = {1, 3, 6, 12, 23};

struct matran
{
    ll f[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0}};
};
ll Mul(ll a, ll b)
{
    if (b <= 1)
        return a % MOD * b;
    ll tmp = Mul(a, b / 2);
    if (b % 2 == 0)
        return tmp % MOD + tmp % MOD;
    else
        return tmp % MOD + tmp % MOD + a % MOD;
}
matran operator*(matran A, matran B)
{
    matran C;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            C.f[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                C.f[i][j] = C.f[i][j] % MOD + Mul(A.f[i][k], B.f[k][j]) % MOD;
                C.f[i][j] %= MOD;
            }
        }
    }
    return C;
}
matran Pow(matran X, ll k)
{
    if (k == 1)
        return X;
    matran tmp = Pow(X, k / 2);
    if (k % 2 == 0)
        return tmp * tmp;
    else
        return tmp * tmp * X;
}
ll Tribonaci(ll n)
{
    if (n <= 5)
        return M[n - 1];
    matran X;
    matran S = Pow(X, n + 2);
    return S.f[2][0] - 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << Tribonaci(n) << "\n";
    }
}

/*

MOD = 1000000000000007

M = [1, 3, 6, 12, 23]

class Matrix:
    def __init__(self):
        self.f = [[1, 0, 0, 0],
                  [0, 1, 1, 0],
                  [1, 1, 0, 1],
                  [0, 1, 0, 0]]

def Mul(a, b):
    if b <= 1:
        return (a * b) % MOD
    tmp = Mul(a, b // 2)
    if b % 2 == 0:
        return (tmp + tmp) % MOD
    else:
        return (tmp + tmp + a) % MOD

def matrix_multiply(A, B):
    C = Matrix()
    for i in range(4):
        for j in range(4):
            C.f[i][j] = 0
            for k in range(4):
                C.f[i][j] = (C.f[i][j] + Mul(A.f[i][k], B.f[k][j])) % MOD
    return C

def matrix_pow(X, k):
    if k == 1:
        return X
    tmp = matrix_pow(X, k // 2)
    if k % 2 == 0:
        return matrix_multiply(tmp, tmp)
    else:
        return matrix_multiply(matrix_multiply(tmp, tmp), X)

def tribonacci(n):
    if n <= 5:
        return M[n - 1]
    X = Matrix()
    S = matrix_pow(X, n + 2)
    return (S.f[2][0] - 1) % MOD

t = int(input())
for _ in range(t):
    n = int(input())
    print(tribonacci(n))

*/