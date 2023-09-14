/*
    Cho một dãy số nguyên gồm N phần tử A[1], A[2], ... A[N].

    Biết rằng dãy con tăng là 1 dãy A[i1],... A[ik]

    thỏa mãn i1 < i2 < ... < ik và A[i1] < A[i2] < .. < A[ik].

    Hãy cho biết dãy con tăng dài nhất của dãy này có bao nhiêu phần tử?

Input:

    Dòng 1 gồm 1 số nguyên là số N (1 ≤ N ≤ 1000).

    Dòng thứ 2 ghi N số nguyên A[1], A[2], .. A[N] (1 ≤ A[i] ≤ 1000).

Output:

    Ghi ra độ dài của dãy con tăng dài nhất.

Ví dụ:

Input               Output

6

1 2 5 4 6 2         4
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

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int dp[n + 1];
    for (int i = 1; i <= n; i++)
        dp[i] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (a[i] > a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(dp, dp + n) << "\n";
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}

// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// void solve()
// {
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     vector<int> v;
//     v.push_back(a[0]);
//     for (int i = 1; i < n; i++)
//     {
//         if (a[i] > v[v.size() - 1])
//             v.push_back(a[i]);
//         else
//         {
//             auto it = lower_bound(v.begin(), v.end(), a[i]);
//             *it = a[i];
//         }
//     }
//     cout << v.size();
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int t = 1;
//     // cin >> t;
//     while (t--)
//         solve();
// }