

/*

    Cho dãy số nguyên A[] độ dài N. Xác định số lượng chỉ số M

    (M < N) thỏa mãn: nếu sắp xếp đoạn con (A1,…,AM) và (AM+1, …, AN)

    theo thứ tự tăng dần thì được dãy số A tăng dần.

Input

    Dòng đầu tiên ghi số bộ test T

    Mỗi bộ test bắt đầu bằng một dòng chứa số N (2 ≤ N ≤ 105)

    Dòng tiếp theo ghi N số của dãy A (|Ai| ≤ 109)
Output

    Với mỗi bộ test:

    Dòng đầu tiên ghi số K là số lượng vị trí M tìm được

    Dòng thứ 2 ghi ra K số theo thứ tự tăng dần lần lượt

    là các chỉ số thỏa mãn. Nếu K = 0 thì dòng này bỏ trống.

Ví dụ

Input               Output

2

2

2 1                 0

5

2 1 3 5 4           2
                    2 3

*/

#include <iostream>
#include <set>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll M[100000];
        for (int i = 0; i < n; i++)
            cin >> M[i];
        ll A[100000], B[100000];
        A[0] = M[0];
        B[n - 1] = M[n - 1];
        for (int i = 1; i < n; i++)
            A[i] = max(A[i - 1], M[i]);
        for (int i = n - 2; i >= 0; i--)
            B[i] = min(B[i + 1], M[i]);
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (A[i] <= B[i + 1])
                cnt++;
        }
        cout << cnt << "\n";
        for (int i = 0; i < n - 1; i++)
        {
            if (A[i] <= B[i + 1])
                cout << i + 1 << " ";
        }
        cout << "\n";
    }
}