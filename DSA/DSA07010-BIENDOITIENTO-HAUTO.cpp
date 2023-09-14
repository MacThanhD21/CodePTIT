

/*

    Hãy viết chương trình chuyển đổi biểu thức biểu diễn 

    dưới dạng tiền tố về dạng hậu tố.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T;

    Những dòng tiếp theo mỗi dòng đưa vào một bộ test. 
    
    Mỗi bộ test là một biểu thức tiền tố exp.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ràng buộc:

    T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤106.

Ví dụ:

Input                   Output

2

*+AB-CD                 AB+CD-*

*-A/BC-/AKL             ABC/-AK/L-*

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        cin >> s;
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (isalpha(s[i]))
            {
                string res = "";
                res += s[i];
                st.push(res);
            }
            else
            {   
                string o1 = st.top();
                st.pop();
                string o2 = st.top();
                st.pop();
                string o3 = o1 + o2 + s[i];
                st.push(o3);
            }
        }
        cout << st.top() << "\n";
    }
}