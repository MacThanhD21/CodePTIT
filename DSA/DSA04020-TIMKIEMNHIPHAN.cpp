
/*

    Cho dãy số A[] gồm có N phần tử đã được sắp xếp tăng dần và số K.

    Nhiệm vụ của bạn là kiểm tra xem số K có xuất hiện trong dãy số 
    
    hay không. Nếu có hãy in ra vị trí trong dãy A[], nếu không in ra “NO”.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

    Mỗi test bắt đầu bằng số nguyên N và K (N ≤ 100 000, 0 ≤ K ≤ 106).

    Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 106), các phần tử là riêng biệt.

Output: 

    Với mỗi test in ra trên một dòng đáp án tìm được.

Ví dụ:

Input               Output

2

5 3

1 2 3 4 5           3

6 5

0 1 2 3 9 10        NO

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int l = 1, r = n;
        bool check = false;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[m] == k)
            {
                cout << m << "\n";
                check = true;
                break;
            }
            else if (a[m] < k)
                l = m + 1;
            else
                r = m - 1;
        }
        if (!check)
            cout << "NO\n";
    }
}