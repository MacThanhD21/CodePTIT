
/*

    Cho dãy số A[] gồm có N phần tử. Bạn cần tìm chênh lệch 
    
    nhỏ nhất giữa hai phần tử bất kì trong dãy số đã cho.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

    Mỗi test gồm số nguyên N (1≤ N ≤ 100 000).

    Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).

Output: 

    Với mỗi test, in ra trên một dòng là đáp án tìm được.

Ví dụ:

Input                       Output

3

6

1 5 3 19 18 25              1

4

30 5 20 9                   4

7

1 19 2 31 38 25 100         1


*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        ll Minimum = 1e9;
        for (int i = 0; i < n - 1; i++)
        {
            Minimum = min(Minimum, 1ll * a[i + 1] - a[i]);
        }
        cout << Minimum << "\n";
    }
}