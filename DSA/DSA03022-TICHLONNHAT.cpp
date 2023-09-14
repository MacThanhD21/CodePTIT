

/*

    Cho dãy số A gồm N phần tử là các số nguyên. 
    
    Hãy tính tích lớn nhất của 

    2 hoặc 3 phần tử trong dãy.

Input

    Dòng đầu tiên ghi số N (3 ≤ N ≤ 10000)

    Dòng thứ 2 ghi N số của dãy A (|Ai| ≤ 1000)

Outpput

    Ghi ra kết quả trên một dòng

Ví dụ

Input               Output

6                   250

5 10 -2 3 5 2

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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        ll Max1 = max(a[0] * a[1], a[0] * a[1] * a[n - 1]);
        ll Max2 = max(a[n - 1] * a[n - 2], a[n - 1] * a[n - 2] * a[n - 3]);
        cout << max(Max1, Max2) << "\n";
    }
}