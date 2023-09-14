
/*

    Cho mảng A[] gồm n phần tử và số k. Đếm tất cả các cặp phần tử
    
    của mảng có tổng bằng k. Ví dụ A[] = {1, 5, 3, 4, 2 }, k = 7
    
    ta có kết quả là 2 cặp (3, 4), (5, 2).

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào T bộ test. 
    
    Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là 
    
    số phần tử của mảng A[] và k; dòng tiếp theo là n số 
    
    A[i] của mảng A[]các số được viết cách nhau một vài khoảng trống.

    T, n, k, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤100; 0≤ k ≤100, 0≤ A[i] ≤103.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Input               Output

2
5 9 
1 5 4 1 2           1

3 2
1 1 1               3

*/

#include <iostream>
#include <map>
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

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        int A[n];
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            m[A[i]]++;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += m[k - A[i]];
            if (A[i] == k - A[i])
                cnt--;
        }
        cout << cnt / 2 << endl;
    }
    return 0;
}
