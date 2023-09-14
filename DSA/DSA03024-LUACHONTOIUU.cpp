/*


    Bạn được giao cho N công việc, công việc thứ i có thời gian

    bắt đầu là A[i] và kết thúc tại B[i]. Tại một thời điểm,

    bạn chỉ có thể làm một công việc.

    Bạn hãy lựa chọn các công việc một cách tối ưu sao cho

    số công việc làm được là nhiều nhất.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

    Mỗi test gồm 1 số nguyên N ( 1 ≤ N ≤ 100 000).

    N dòng tiếp theo, mỗi dòng gồm 2 số A[i] và B[i]

    (0 ≤ A[i] < B[i] ≤ 106).

Output:

    Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input           Output

1

6

5 9

1 2

3 4             4

0 6

5 7

8 9

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define quick()                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define pb push_back
#define is insert
#define FOR0(i, a, b) for (int i = a; i < b; i++)
#define FOR1(i, a, b) for (int i = a; i <= b; i++)
#define fi first
#define se second

const int mod = 1e9 + 7;
const int mnX = 1e6 + 5;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.se < b.se;
}

void solve()
{
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a, a + n, cmp);
    ll ans = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].fi > res)
        {
            ++ans;
            res = a[i].se;
        }
    }
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}