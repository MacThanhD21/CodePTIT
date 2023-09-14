
/*

    Dãy số nguyên dương vô hạn A[] được định nghĩa một cách đệ quy như sau:

    A[0] = 0

    A[1] = 1;

    A[i] = A[i-1] + A[i-2] với mọi n ≥ 2.

    Cho số nguyên dương N không quá 109. 
    
    Hãy xác định số thứ N trong dãy A[]. 
    
    Nếu kết quả quá lớn, hãy in ra theo modulo 109+7.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 1000).

    Mỗi test bắt gồm một số nguyên N (1 ≤ N ≤ 109).

Output: 


    Với mỗi test, in ra đáp án trên một dòng.
Ví dụ:

Input           Output

2

2               1

6               

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

matrix powMod(matrix a, ll k)
{
    if (k == 1)
        return a;
    matrix tmp = powMod(a, k / 2);
    if (k % 2 == 1)
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

    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll n;
        cin >> n;
        matrix res;
        res.a[0][0] = 1;
        res.a[0][1] = 1;
        res.a[1][0] = 1;
        res.a[1][1] = 0;
        matrix ans = powMod(res, n);
        cout << ans.a[0][1] << "\n";
    }
}

/*

mod = 10**9 + 7

class Matrix:
    def __init__(self):
        self.a = [[1, 1], [1, 0]]

    def __mul__(self, other):
        res = Matrix()
        for i in range(2):
            for j in range(2):
                res.a[i][j] = 0
                for k in range(2):
                    res.a[i][j] += self.a[i][k] * other.a[k][j]
                    res.a[i][j] %= mod
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
    n = int(input())
    res = Matrix()
    ans = pow_mod(res, n)
    print(ans.a[0][1])

*/