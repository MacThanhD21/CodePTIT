
/*

    Cho số nguyên dương n. Hãy cho biết có bao nhiêu dãy số nguyên dương
    
    có tổng các phần tử trong dãy bằng n. 

Dữ liệu vào: 

    dòng đầu tiên chứa số nguyên T là số bộ dữ liệu, 
    
    mỗi bộ dữ liệu ghi một số nguyên dương n duy nhất không qua 10^18. 

Kết quả: 

    Mỗi bộ dữ liệu ghi ra một số nguyên duy nhất là số dư 
    
    của kết quả tìm được khi chia cho 123456789.

Ví dụ:

Input           Output

1

3               4

*/

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int mod = 123456789;

ll powMod(ll x, ll y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    ll tmp = powMod(x, y / 2) % mod;
    if (y & 1)
        return tmp * tmp * x;
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
        ll n;
        cin >> n;
        cout << powMod(2, n - 1) << "\n";
    }
}


/*

mod = 123456789

def powMod(x, y):
    if y == 0:
        return 1
    if y == 1:
        return x
    tmp = powMod(x, y // 2) % mod
    if y % 2 == 1:
        return (tmp * tmp * x) % mod
    else:
        return (tmp * tmp) % mod

t = int(input())
for _ in range(t):
    n = int(input())
    result = powMod(2, n - 1)
    print(result)

*/