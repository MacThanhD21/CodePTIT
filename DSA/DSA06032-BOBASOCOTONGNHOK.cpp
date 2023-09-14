
/*

    Cho dãy số A[] gồm có N phần tử.

    Nhiệm vụ của bạn là hãy đếm số bộ ba (i, j, k) 
    
    mà A[i] + A[j] + A[k] < K cho trước.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm số nguyên N và K (1≤ N ≤5000, -109 ≤ K ≤ 109).

    Dòng tiếp theo gồm N số nguyên A[i] (-109 ≤ A[i] ≤ 109).

Output: 

    Với mỗi test, in ra trên một dòng là đáp án tìm được.

Ví dụ:

Input               Output

2

4 2

-2 0 1 3            2

5 12

5 1 3 4 7           4

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define is insert
#define fi first
#define se second

const int mod = 1e9 + 7;
const int maxx = 1e7 + 5;


void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int &x : a)
        cin >> x;
    sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int pos = lower_bound(a + j + 1, a + n, k - a[i] - a[j]) - a;
            --pos; // vi tri thoa mãn a[k] + a[i] + a[j] < k
            // pos = pos - j - 1;
            // cout << pos << " ";
            ans += 1ll * (pos - j);
        }
    }
    // cout << "\n";
    cout << ans << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}