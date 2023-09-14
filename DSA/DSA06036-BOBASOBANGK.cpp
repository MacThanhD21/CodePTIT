
/*

    Cho dãy số A[] gồm có N phần tử.

    Nhiệm vụ của bạn là hãy kiểm tra tồn tại bộ ba 
    
    (i, j, k) mà A[i] + A[j] + A[k] = K cho trước hay không.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm số nguyên N và K (1≤ N ≤5000, 0 ≤ K ≤ 10^9).

    Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).

Output: 

    Với mỗi test, in ra trên một dòng là “YES” 
    
    nếu tìm được bộ ba thỏa mãn, “NO” trong trường hợp ngược lại.

Ví dụ:

Input                   Output

2

6 22

1 4 15 6 10 8           YES

3 4

1 1 1                   NO


*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO()                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pb push_back

const int mod = 1e9 + 7;

int main()
{
    IO();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (ll &x : a)
            cin >> x;
        sort(a, a + n);
        bool fag = false;
        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                ll sum = a[i] + a[l] + a[r];
                if (sum == k)
                {
                    cout << "YES\n";
                    fag = true;
                    break;
                }
                else if (sum < k)
                {
                    ++l;
                }
                else
                    --r;
            }
            if (fag)
                break;
        }
        if (!fag)
            cout << "NO\n";
    }
}