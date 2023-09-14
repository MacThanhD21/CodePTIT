

/*

    Cho số nguyên dương N được biểu diễn như một xâu ký tự số. 
    
    Nhiệm vụ của bạn là tìm tổng của tất cả các số tạo bởi các 
    
    xâu con của N. Ví dụ N=”1234” ta có kết quả là 
    
    1670 = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test là một số N.

    T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤1012.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input           Output

2
1234            1670
421             491

*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long

// void TestCase() {
//     string s; cin >> s;
//     long long ans = 0;

//     for (int i = 0; i < s.length(); ++i) {
//         for (int j = i; j < s.length(); ++j) {
//             string temp = s.substr(i, j - i + 1);
//             ans += stoll(temp);
//         }
//     }
//     cout << ans;
// }

void TestCase()
{
    // QHD
    string s;
    cin >> s;
    ll dp[15] = {0}, res = 0;
    // dp[i] : tong các xâu con tính đến vị trí i
    dp[0] = s[0] - '0';
    res = dp[0];
    for (int i = 1; i < s.length(); ++i)
    {
        int num = s[i] - '0'; // them x vao các tổng con
        dp[i] = (i + 1) * num + dp[i - 1] * 10;
        res = res + dp[i];
    }
    cout << res << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        TestCase();
    }
}