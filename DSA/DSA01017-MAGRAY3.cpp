/*

    Số nhị phân được xem là cách mặc định biểu diễn các số.

    Tuy nhiên, trong nhiều ứng dụng của điện tử và truyền thông

    lại dùng một biến thể của mã nhị phân đó là mã Gray.

    Mã Gray độ dài n có mã đầu tiên là n số 0, mã kế tiếp của nó là

    một xâu nhị phân độ dài n khác biệt với xâu trước đó một bít.

    Ví dụ với n=3 ta có 23 mã Gray như sau: 000, 001, 011, 010, 110, 111, 101, 100.

    Hãy viết chương trình chuyển đổi một xâu mã nhị phân X có độ dài n thành một xâu mã Gray.

Input:

    Dòng đầu tiên là số lượng test T.

    T dòng kế tiếp ghi lại mỗi dòng một test.

    Mỗi test là một xâu nhị phân độ dài n.

    T, n thỏa mãn ràng buộc: 1≤T, n≤10.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Input           Output

2

01001           01101

01101           01011

*/

// https://code.ptit.edu.vn/student/question/DSA01017
// MÃ GRAY 3

#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    string s;
    cin >> s;
    string res(1, s[0]);
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] != s[i - 1])
            res.push_back('1');
        else
            res.push_back('0');
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        testCase();
        cout << "\n";
    }
    return 0;
}