
/*

    Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới 
    
    dạng tiền tố về dạng trung tố.

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

*+AB-CD                 ((A+B)*(C-D))

*-A/BC-/AKL             ((A-(B/C))*((A/K)-L)

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define ii pair<int, int>

void solve()
{
    string s;
    cin >> s;
    int n = s.size() - 1;
    stack<string> st;
    for (int i = n; i >= 0; i--)
    {
        if (isalpha(s[i]))
        {
            st.push(s.substr(i, 1));
        }
        else
        {
            if (!st.empty())
            {
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                st.push("(" + s1 + s[i] + s2 + ")");
            }
        }
    }
    cout << st.top() << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T-- > 0)
    {
        solve();
    }
}