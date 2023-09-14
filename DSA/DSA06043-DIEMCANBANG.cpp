
/*

    Cho dãy số A[] gồm có N phần tử nguyên dương. Phần tử thứ i 
    
    được gọi là điểm cân bằng của dãy số nếu như tổng các số bên 
    
    trái bằng tổng các số bên phải của nó.

    Nhiệm vụ của bạn là điểm cân bằng đầu tiên của dãy A[] cho trước. 
    
    Nếu không có đáp án, in ra -1.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

    Mỗi test gồm số nguyên N (1≤ N ≤ 100 000), 
    
    số lượng phần tử trong dãy số ban đầu.

    Dòng tiếp theo gồm N số nguyên A[i] (-1000 ≤ A[i] ≤ 1000).

Output: 

    Với mỗi test, in ra trên một dòng vị trí của điểm cân bằng tìm được.

Ví dụ:

Input                   Output

2

7

-7 1 5 2 -4 3 0         4

5

1 2 3 4 5               -1

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
        ll sumL = 0, sumR = 0;
        for (int i = 0; i < n; i++)
        {
            sumR += a[i];
        }
        bool ok = false;
        for (int i = 0; i < n; i++)
        {
            sumR -= a[i];
            if (sumL == sumR)
            {
                cout << i + 1 << "\n";
                ok = true;
                break;
            }
            else
                sumL += a[i];
        }
        if (!ok)
            cout << "-1\n";
    }
}