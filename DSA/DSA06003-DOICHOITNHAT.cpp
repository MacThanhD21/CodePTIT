
/*

    Cho mảng A[] gồm n phần tử. Hãy tìm số phép đổi chỗ ít nhất 
    
    giữa các phần tử của mảng để mảng A[] được sắp xếp. 
    
    í dụ với A[] = {4, 3, 2, 1} ta cần thực hiện ít nhất 2 phép đổi chỗ: 
    
    Swap(A[0], A[3]),  Swap(A[1], A[2]).

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào T bộ test. 
    
    Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử 
    
    của mảng n và X; dòng tiếp theo là n số A [i] của mảng A [];
    
    các số được viết cách nhau một vài khoảng trống.

    T, n thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤103.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Input               Output

2
4
4 3 2 1             2
5
1 5 4 3 2           2

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
        int n;
        cin >> n;
        int a[n];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            int tmp = a[i], idex = 0;
            // tim phan tu nho nhat tu i + 1 -> n
            for (int j = i + 1; j <= n; j++)
            {
                if (tmp > a[j])
                {
                    tmp = a[j];
                    idex = j;
                }
            }
            // tmp la phan tu min
            if (tmp < a[i])
            {
                ++ans;
                swap(a[idex], a[i]);
            }
        }
        cout << ans << "\n";
    }
}