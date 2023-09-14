
/*


    Cho số nguyên dương N. Mỗi bước, bạn sẽ biến đổi N thành [N/2],

    N mod 2, [N/2]. Sau khi thực hiện một cách triệt để,

    ta thu được một dãy số chỉ toàn số 0 và 1.

    Nhiệm vụ của bạn là hãy đếm các số bằng 1 trong đoạn [L, R] của dãy số cuối cùng.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm 3 số nguyên N, L, R (1 ≤ N, L, R < 250, 0 ≤ R-L ≤ 100 000).

Output:

    Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input           Output

2

7 2 5           4

10 3 10         5

Giải thích test 1: [7] à [3, 1, 3] à [1, 1, 1, 1, 3] à [1, 1, 1, 1, 1, 1, 1].

Giải thích test 2: Dãy số sau khi biến đổi là [1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1].
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

vector<ll> X;

ll dem(ll k, ll n, ll pos)
{
    if (k % 2 == 1)
        return 1;
    if (k < X[pos])
        return dem(k, n / 2, pos - 1);
    else if (k == X[pos])
    {
        return n % 2;
    }
    else if (k > X[pos])
        return dem(2 * X[pos] - k, n / 2, pos - 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, l, r;
        cin >> n >> l >> r;
        X.clear();
        ll x = 1;
        ll y = n;
        while (n / 2 > 0)
        {
            x *= 2;
            X.push_back(x);
            n /= 2;
        }
        ll res = 0;
        for (ll i = l; i <= r; i++)
        {
            res += dem(i, y, X.size() - 1);
        }
        cout << res << "\n";
    }
}


/*
def dem(k, n, pos):
    if k % 2 == 1:
        return 1
    if k < X[pos]:
        return dem(k, n // 2, pos - 1)
    elif k == X[pos]:
        return n % 2
    elif k > X[pos]:
        return dem(2 * X[pos] - k, n // 2, pos - 1)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, l, r = map(int, input().split())
        X = []
        x = 1
        y = n
        while n // 2 > 0:
            x *= 2
            X.append(x)
            n //= 2
        res = 0
        for i in range(l, r + 1):
            res += dem(i, y, len(X) - 1)
        print(res)



*/