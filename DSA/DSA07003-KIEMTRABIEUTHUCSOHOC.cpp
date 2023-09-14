
/*

    Cho biểu thức số học, hãy cho biết biểu thức số học có 
    
    dư thừa các cặp ký hiệu ‘(’,’) ‘ hay không?

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T;

    Những dòng tiếp theo mỗi dòng đưa vào một bộ test. 
    
    Mỗi bộ test là một biểu thức.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Contrains:

    T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.
    
Ví dụ:

Input               Output

3

((a+b))             Yes

(a + (b)/c)         Yes

(a + b*(c-d))       No

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define ii pair<int, int>

bool solve()
{
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ')')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            bool check = false;
            while (!st.empty() && st.top() != '(')
            {
                if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                {
                    check = true;
                    st.pop();
                }
                else
                    st.pop();
            }
            st.pop();
            if (!check)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T-- > 0)
    {
        if (solve())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}