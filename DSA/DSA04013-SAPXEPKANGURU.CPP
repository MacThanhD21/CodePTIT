/*

    Có N con kanguru trong vườn thú, con thứ i có chiều cao bằng A[i].

    Con kanguru có chiều cao X có thể chứa được một con có chiều cao bằng Y

    trong túi của nó nếu như X >= 2*Y.

    Một con đã chứa một con kanguru rồi, thì không thể nhảy vào túi một con kanguru khác.

    Bầy Kanguru rất thích chơi trốn tìm, vì vậy chúng thường xuyên nhảy vào túi của nhau.

    Các bạn hãy tính toán xem trong trường hợp tối ưu, số con kanguru

    nhìn thấy trong vườn thú ít nhất bằng bao nhiêu?

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm số nguyên N (1 ≤ N ≤ 100 000).

    Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 100 000).

Output:

    Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input                   Output

2

8

2 5 7 6 9 8 4 2         5

8

9 1 6 2 6 5 8 3         5

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n, greater<int>());
        int res = 0;
        int l = 0, r = n / 2;
        while (l < n / 2 && r < n)
        {
            if (a[l] >= 2 * a[r])
            {
                res++;
                l++;
                r++;
            }
            else
                r++;
        }
        cout << n - res << "\n";
    }
}

/*

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    res = 0
    l, r = 0, n // 2
    while l < n // 2 and r < n:
        if a[l] >= 2 * a[r]:
            res += 1
            l += 1
            r += 1
        else:
            r += 1
    print(n - res)

*/