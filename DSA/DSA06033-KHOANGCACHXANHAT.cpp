
/*

    Cho dãy số A[] gồm có N phần tử. Bạn cần tìm 2 vị trí i, j 
    
    sao cho j-i lớn nhất và A[j] > A[i].

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

    Mỗi test gồm số nguyên N (1≤ N ≤ 100 000).

    Dòng tiếp theo gồm N số nguyên A[i] (-10^6 ≤ A[i] ≤ 10^6).

Output: 

    Với mỗi test, in ra trên một dòng là giá trị của hiệu j-i tìm được.

Ví dụ:

Input                           Output

3

9

34 8 10 3 2 80 30 33 1          6

6

1 2 3 4 5 6                     5

6

6 5 4 3 2 1                     -1

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
        int a[100000];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int mintoLeft[100000] = {}, maxtoRight[100000] = {};

        mintoLeft[0] = a[0];
        maxtoRight[n - 1] = a[n - 1];
        for (int i = 1; i < n; i++)
        {
            mintoLeft[i] = min(a[i], mintoLeft[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            maxtoRight[i] = max(a[i], maxtoRight[i + 1]);
        }
        int i = 0, j = 0;

        int ans = -1;
        while (i < n && j < n)
        {
            if (mintoLeft[i] < maxtoRight[j])
            {
                ans = max(ans, j - i);
                ++j;
            }
            else
            {
                ++i;
            }
        }
        cout << ans << "\n";
    }
}