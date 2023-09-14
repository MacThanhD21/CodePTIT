
/*

    Cho mảng A[] gồm n số nguyên dương và số K. Hãy đếm số các cặp phần tử

    có hiệu nhỏ hơn K. Ví dụ A[] = {1, 10, 4, 2 }, K=3 ta nhận được kết quả

    là 2 tương ứng với các cặp (1, 2), (4, 2).

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Mỗi bộ test gồm hai dòng: dòng đầu tiên ghi số n và số K;

    dòng tiếp theo là n số A[i] ; các số được viết cách nhau một vài khoảng trống.

    T, n, k, A[i] thỏa mãn ràng buộc: 1 ≤  T  ≤ 100; 1 ≤  n  ≤ 104; 1 ≤  k ≤ 103; 1 ≤  A[i]  ≤ 105.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input	        Output
2
4 3             2
1 10 4 2
3 5             3
2 3 4

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int firstPos(int a[], int l, int r, int x)
{
    int res = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] < x)
        {
            res = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        ll cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int res = firstPos(a, i + 1, n - 1, k + a[i]);
            // auto it=lower_bound(a+i+1,a+n,k+a[i]);
            if (res != -1)
                cnt += res - i;
            // cnt+=it-(a+i)-1;
        }
        cout << cnt << "\n";
    }
    return 0;
}



/*


def first_pos(a, l, r, x):
    res = -1
    while l <= r:
        m = (l + r) // 2
        if a[m] < x:
            res = m
            l = m + 1
        else:
            r = m - 1
    return res

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    cnt = 0
    for i in range(n - 1):
        res = first_pos(a, i + 1, n - 1, k + a[i])
        if res != -1:
            cnt += res - i
    print(cnt)

*/