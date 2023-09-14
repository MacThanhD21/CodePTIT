
/*

    Tại ngân hàng có các mệnh giá bằng 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000. 
    
    Tổng số tiền cần đổi có giá trị bằng N.  Hãy xác định xem có ít nhất bao nhiêu 
    
    tờ tiền sau khi đổi tiền?

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 50).  
    
    Mỗi test gồm 1 số nguyên N ( 1 ≤ N ≤ 100 000).

Output:  

    Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input           Output

2

70              2

121             3

*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
        int ans = 0;
        for (int i = 9; i >= 0; i--)
        {
            ans += n / a[i];
            n %= a[i];
        }
        cout << ans << "\n";
    }
}