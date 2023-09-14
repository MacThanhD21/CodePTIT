

/*

    Cho dãy số A[] có N phần tử là các chữ số từ 0 đến 9.

    Nhiệm vụ của bạn là hãy chọn lấy một tổ hợp các phần tử

    và sắp xếp chúng sao cho thu được số lớn nhất chia hết cho 3.

    Nếu không tìm được số nào, in ra -1.

Input:

    Dòng đầu tiên là số lượng bộ test T (1 ≤ N ≤ 50).

    Mỗi test bắt đầu bởi số nguyên N (1 ≤ N ≤ 100 000).

    Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 9).

Output:

    Với mỗi test, in ra đáp án tìm được trên một dòng.

Ví dụ:

Input               Output

3

3

8 1 9               981

5

8 1 7 6 0           8760

2   

5 2                 -1

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <string>
#include <climits>
#include <set>
#include <stack>
#include <queue>

using namespace std;

#define ll long long
#define p(x) pair<x, x>
#define v(x) vector<x>
#define FORD(i, l, r) for (int i = l; i < r; i++)
#define FORE(i, l, r) for (int i = r - 1; i >= 0; i--)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define cin(M) FORD(i, 0, n) cin >> M[i];
#define sz(M) M.size();
#define all(M) M.begin(), M.end()
#define ft first
#define sd second
#define pb push_back
#define pf push_front

bool check[10000];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, M[100000];
        cin >> n;
        cin(M);
        int N[10] = {0};
        int sum = 0;
        FORD(i, 0, n)
        N[M[i]]++, sum += M[i];
        bool check = false;
        if (sum % 3 == 1)
        {
            if (N[1] > 0)
                N[1]--, check = true;
            else if (N[4] > 0)
                N[4]--, check = true;
            else if (N[7] > 0)
                N[7]--, check = true;
        }
        else if (sum % 3 == 2)
        {
            if (N[2] > 0)
                N[2]--, check = true;
            else if (N[5] > 0)
                N[5]--, check = true;
            else if (N[8] > 0)
                N[8]--, check = true;
        }
        else
            check = true;
        if (!check)
        {
            cout << -1 << "\n";
            continue;
        }
        int k = 10, ok = 1;
        while (k--)
            while (N[k]--)
                cout << k, ok = 0;
        if (ok)
            cout << -1;
        cout << "\n";
    }
    return 0;
}