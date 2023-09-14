
/*

    Giả sử bạn cần viết N ký tự giống nhau lên màn hình. Bạn chỉ được phép thực hiện 
    
    ba thao tác dưới đây với chi phí thời gian khác nhau:

        Thao tác insert: chèn một ký tự với thời gian là X.

        Thao tác delete: loại bỏ ký tự cuối cùng với thời gian là Y.

        Thao tác copying: copy và paste tất cả các ký tự đã viết để số ký tự 
        được nhân đôi với thời gian là Z.

    Hãy tìm thời gian ít nhất để có thể đưa ra màn hình N ký tự giống nhau. 
    
    Ví dụ với N = 9, X =1, Y = 2, Z =1 ta có kết quả là 5 bằng cách thực hiện: 
    
    insert, insert, copying, copying, insert.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N 
    
    là số các ký tự giống nhau cần viết lên màn hình; 
    
    dòng tiếp theo đưa vào bộ ba số X, Y, Z tương ứng với 
    
    thời gian thực hiện ba thao tác; các số được viết cách nhau một vài khoảng trống.

    T, N, X, Y, Z thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤100; 1≤X, Y, Z ≤100.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input               Output

2
9
1 2 1               5
10
2 5 4               14

*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y, z;
        cin >> n >> x >> y >> z;

        // Initialize the dp table
        vector<int> dp(n + 1, INF);
        // dp[i] : lưu thời gian ngắn nhất để tạo ra được i ký tự.
        dp[0] = 0;                         // khonog mất thời gian để tạo ra 0 ký tự
        dp[1] = x;                         // thời gian tạo ra ký tự đầu tiên luôn luôn bằng x, cơ sở để làm được những thao tác khác.
        dp[2] = min(dp[1] + x, dp[1] + z); // cân nhắc giữa thêm ký tự mới và copy_paste xem cái nào thời gian ít hơn
        for (int i = 3; i <= n; i++)
        {
            // Case 1: insert
            dp[i] = dp[i - 1] + x;

            // Case 2: copy and paste
            if (i % 2 == 0)
            {
                dp[i] = min(dp[i], dp[i / 2] + z); // nếu tạo ra được chẵn ký tự thì chỉ cần copy và paste sẽ đến tạo ra được N ký tự nhanh nhất
            }

            // Case 3: lua chọn thời gian ngắn nhất giữa insert & (copy_paste + delete)
            // TH : N là số lẻ (lựa chọn ở bước cuối).
            else
            {
                dp[i] = min(dp[i], dp[i / 2 + 1] + z + y);
            }
        }

        cout << dp[n] << "\n";
    }
}