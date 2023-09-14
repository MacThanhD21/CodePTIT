
/*

    Một dãy số tự nhiên bắt đầu bởi con số 1 và được thực hiện N-1

    phép biến đổi “gấp đôi” dãy số như sau:

    Với dãy số A hiện tại, dãy số mới có dạng A, x, A trong đó

    x là số tự nhiên bé nhất chưa xuất hiện trong A.

    Ví dụ với 2 bước biến đổi, ta có [1] - [1 2 1] - [1 2 1 3 1 2 1].

    Các bạn hãy xác định số thứ K trong dãy số cuối cùng là bao nhiêu?

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm số nguyên dương N và K (1 ≤ N ≤ 50, 1 ≤ K ≤ 2N - 1).

Output:

    Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input               Output

2

3 2                 2

4 8                 4

Giải thích test 1: Dãy số thu được là [1, 2, 1, 3, 1, 2, 1].

Giải thích test 2: Dãy số thu được là [1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1].
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll Ping(ll n, ll k)
{
    ll leng = pow(2, n - 1);

    if (k == leng)
    {
        return n;
    }
    if (k < leng)
    {
        return Ping(n - 1, k);
    }
    else
    {
        return Ping(n - 1, k - leng);
    }
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
        cout << Ping(n, k) << "\n";
    }
}


// python

// def ping(n, k):
//     leng = 2 ** (n - 1)

//     if k == leng:
//         return n
//     if k < leng:
//         return ping(n - 1, k)
//     else:
//         return ping(n - 1, k - leng)

// if __name__ == "__main__":
//     t = int(input())
//     for _ in range(t):
//         n, k = map(int, input().split())
//         print(ping(n, k))
