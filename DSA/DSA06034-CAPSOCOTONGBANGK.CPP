

/*

    Cho dãy số A[] gồm có N phần tử.

    Nhiệm vụ của bạn là đếm xem có bao nhiêu cặp

    (i, j) mà A[i] + A[j] = K cho trước.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

    Mỗi test gồm số nguyên N và K (1≤ N ≤ 100 000, 0 ≤ K ≤ 10^9).

    Dòng tiếp theo gồm N số nguyên A[i] (-10^9 ≤ A[i] ≤ 10^9).

Output:

    Với mỗi test, in ra trên một dòng là đáp án thu được.

Ví dụ:

Input                               Output

4

4 6

1 5 7 -1                            2

5 6

1 5 7 -1 5                          3

4 2

1 1 1 1                             6

13 11

10 12 10 15 -1 7 6 5 4 2 1 1 1      9

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        unordered_map<int, int> m;
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (m.count(k - a))
            {
                cnt += 1ll * m[k - a];
            }
            if (m.count(a))
            {
                m[a]++;
            }
            else
            {
                m[a] = 1;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
