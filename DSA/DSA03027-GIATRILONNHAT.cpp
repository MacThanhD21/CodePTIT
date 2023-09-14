
/*

    Cho dãy số nguyên A[] có N phần tử.

    Gọi f(i,j) = |ai| + |ai+1| + … + |aj|

    Gọi g(i,j) = ai + ai+1 + … + aj

    Với tất cả các cặp 1 ≤ i ≤ j ≤ N.

    Hãy tính giá trị lớn nhất của f(i,j) + g(i,j).

Input

    Dòng đầu ghi số N (1 ≤ N ≤ 50000)

    Dòng thứ 2 ghi N số nguyên của dãy A[]

Output

    Ghi ra giá trị lớn nhất của f(i,j) + g(i,j)

Ví dụ

Input               Output

5                   26
-3 5 -10 8 -2

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 50005;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
        {
            ans += (1ll * a[i] * 2);
        }
    }
    cout << ans << "\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
}