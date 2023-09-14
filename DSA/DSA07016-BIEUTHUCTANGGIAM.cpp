
/*

    Cho dãy ký tự S chỉ bao gồm các ký tự I hoặc D. 
    
    Ký tự I được hiểu là tăng (Increasing) 
    
    ký tự D được hiểu là giảm (Decreasing). 
    
    Sử dụng các số từ 1 đến 9, hãy đưa ra số nhỏ nhất 
    
    được đoán nhận từ S. Chú ý, các số không được phép lặp lại. 
    
    Dưới đây là một số ví dụ mẫu:

    A[] = “I”               : số tăng nhỏ nhất là 12.
    A[] = “D”               : số giảm nhỏ nhất là 21
    A[] =”DD”               : số giảm nhỏ nhất là 321
    A[] = “DDIDDIID”        : số thỏa mãn 321654798

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào T bộ test. 
    
    Mỗi bộ test là một xâu S

    T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ length(S) ≤8; .

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input:              Output:

4

I                   12
D                   21
DD                  321
DDIDDIID            321654798

*/

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    stack<int> st;
    for (int i = 0; i <= s.size(); i++)
    {
        st.push(i + 1);
        if (s[i] == 'I' || i == s.size())
        {
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
        }
        else if (s[i] == 'D')
        {
            if (i == s.size())
            {
                while (!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
            }
        }
    }
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
        cout << "\n";
    }
}