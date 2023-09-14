/*

    Số nhị phân được xem là cách mặc định biểu diễn các số. 

    Tuy nhiên, trong nhiều ứng dụng của điện tử và truyền thông 

    lại dùng một biến thể của mã nhị phân đó là mã Gray. 

    Mã Gray độ dài n có mã đầu tiên là n số 0, mã kế tiếp của nó 

    là một xâu nhị phân độ dài n khác biệt với xâu trước đó một bít. 

    Ví dụ với n=3 ta có 23 mã Gray như sau: 000, 001, 011, 010, 110, 111, 101, 100.

    Hãy viết chương trình liệt kê các mã Gray có độ dài n.

Input:

    Dòng đầu tiên là số lượng test T.

    T dòng kế tiếp ghi lại mỗi dòng một test.
    
    Mỗi test là một số tự nhiên n.

    T, n thỏa mãn ràng buộc: 1≤T, n≤10.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Input:          Output:

2

3               000 001 011 010 110 111 101 100

4               0000 0001 0011 0010 0110 0111 0101 0100 1100 1101 1111 1110 1010 1011 1001 1000


*/

#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    int n;
    cin >> n;

    vector<string> a;
    a.push_back("0");
    a.push_back("1");

    for (int i = 2; i <= n; ++i)
    {
        int l = a.size();
        for (int i = l - 1; i >= 0; --i)
        {
            a.push_back(a[i]);
        }
        for (int i = 0; i < l; ++i)
        {
            a[i] = '0' + a[i];
        }
        for (int i = l; i < a.size(); ++i)
        {
            a[i] = '1' + a[i];
        }
    }

    for (string i : a)
        cout << i << " ";
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