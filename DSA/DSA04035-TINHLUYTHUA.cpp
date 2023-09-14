/*

    Cho hai số nguyên không âm a và b. Hãy tính ab.

    Nếu kết quả quá lớn hãy chia dư cho 109 + 7.

Input

    Gồm không quá 20 bộ test, mỗi test ghi trên một dòng hai số a,b; 
    
    a không quá 9 chữ số, b không quá 18 chữ số.

    Input kết thúc khi a = b = 0

Output

    Với mỗi test ghi ra kết quả tính được trên một dòng.

Ví dụ

Input               Output

2 3

2 4                 8

3 2                 16

0 0                 9

*/

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
#define ll long long

ll powMod(int n, ll k)
{
    if (k == 0)
        return 1;
    ll x = powMod(n, k / 2);
    if (k % 2 == 0)
        return x * x % mod;
    return n * (x * x % mod) % mod;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    while (1)
    {
        ll n, k;
        cin >> n >> k;
        if (n == 0 && k == 0)
            break;
        cout << powMod(n, k) << "\n";
    }
}