

/*

    Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới 
    
    dạng trung tố về dạng hậu tố.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T;

    Những dòng tiếp theo mỗi dòng đưa vào một bộ test. 
    
    Mỗi bộ test là một biểu thức tiền tố exp.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ràng buộc:

    T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤10.

    Các phép toán bao gồm +, -, *, /, ^. Phép lũy thừa 
    
    có ưu tiên cao hơn nhân chia và cộng trừ.

Ví dụ:

Input               Output

2

(A+(B+C)            ABC++

((A*B)+C)           AB*C+   

*/

#include <bits/stdc++.h>

using namespace std;

int pre(char x)
{
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st1;
        stack<string> st2;
        for (char x : s)
        {
            if (isalpha(x))
            {
                string tmp = "";
                tmp += x;
                st2.push(tmp);
            }
            else if (x == '(')
            {
                st1.push(x);
            }
            else if (x == ')')
            {
                while (!st1.empty() && st1.top() != '(')
                {
                    string tmp = "";
                    tmp += st1.top();
                    st1.pop();
                    st2.push(tmp);
                }
                st1.pop();
            }
            else
            {
                while (!st1.empty() && pre(st1.top()) >= pre(x))
                {
                    string tmp = "";
                    tmp += st1.top();
                    st1.pop();
                    st2.push(tmp);
                }
                st1.push(x);
            }
        }
        while (!st1.empty())
        {
            string tmp = "";
            tmp += st1.top();
            st1.pop();
            st2.push(tmp);
        }
        string ans = "";
        while (!st2.empty())
        {
            ans += st2.top();
            st2.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
}