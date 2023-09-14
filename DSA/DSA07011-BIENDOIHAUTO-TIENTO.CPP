

/*

    Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng 
    
    hậu tố về dạng tiền tố.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T;

    Những dòng tiếp theo mỗi dòng đưa vào một bộ test. 
    
    Mỗi bộ test là một biểu thức tiền tố exp.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ràng buộc:

    T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤106.

Ví  dụ:

Input               Output

2

AB+CD-*             *+AB-CD

ABC/-AK/L-*         *-A/BC-/AKL

*/

#include <bits/stdc++.h>

using namespace std;

void solve(string s)
{
    stack<string> st;
    string ans = "";
    for (char x : s)
    {
        if (isalpha(x))
        {
            string tmp = "";
            tmp += x;
            st.push(tmp);
        }
        else
        {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string ans = x + s2 + s1;
            st.push(ans);
        }
    }
    cout << st.top() << "\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t --> 0)
    {
        string s; cin >> s;
        solve(s);
    }
}