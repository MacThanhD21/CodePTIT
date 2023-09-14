
/*

    Cho ma trận vuông A kích thước N x N. Nhiệm vụ của bạn là hãy 
    
    tính ma trận X = AK với K là số nguyên cho trước. Sau đó, 
    
    tính tổng các phần tử của cột cuối cùng. Đáp số có thể rất lớn, 
    
    hãy in ra kết quả theo modulo 109+7.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 100).

    Mỗi test bắt gồm một số nguyên N và K (1 ≤ N ≤ 10, 1 ≤ K ≤ 109) 
    
    là kích thước của ma trận và số mũ.

Output: 

    Với mỗi test, in ra kết quả của ma trận X.

Ví dụ:

Input           Output

2

2 5

1 1

1 0

3 1000000000    8

1 2 3           581039956

4 5 6

7 8 9              



*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define F first
#define S second
#define PB push_back
#define MP make_pair

const int mod = 1e9 + 7;

struct matrix
{
    ll a[10][10];
    ll n;

    matrix operator*(matrix dif)
    {
        matrix res;
        res.n = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res.a[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    res.a[i][j] += a[i][k] * dif.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

matrix Pow(matrix a, ll k)
{
    if (k == 1)
        return a;

    matrix tmp = Pow(a, k / 2);
    if (k & 1)
        return tmp * tmp * a;
    else
        return tmp * tmp;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        matrix u;
        u.n = n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> u.a[i][j];
            }
        }

        matrix q = Pow(u, k);

        ll sumCol = 0;
        for (int i = 0; i < n; i++)
        {
            sumCol = ((sumCol % mod) + (q.a[i][n - 1] % mod)) % mod;
        }
        cout << sumCol << "\n";
    }
}

/*

mod = 10**9 + 7

class Matrix:
    def __init__(self, n):
        self.n = n
        self.a = [[0] * n for _ in range(n)]

    def __mul__(self, other):
        res = Matrix(self.n)
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    res.a[i][j] = (res.a[i][j] + self.a[i][k] * other.a[k][j]) % mod
        return res

def pow_mod(a, k):
    if k == 1:
        return a

    tmp = pow_mod(a, k // 2)
    if k % 2 == 1:
        return tmp * tmp * a
    else:
        return tmp * tmp

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())

    u = Matrix(n)

    for i in range(n):
        u.a[i] = list(map(int, input().split()))

    q = pow_mod(u, k)

    sum_col = 0
    for i in range(n):
        sum_col = (sum_col + q.a[i][n - 1]) % mod

    print(sum_col)

*/