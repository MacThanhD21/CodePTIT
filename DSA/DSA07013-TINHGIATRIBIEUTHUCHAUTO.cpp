
/*

    Hãy viết chương trình chuyển tính toán 
    
    giá trị của biểu thức hậu tố.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T;

    Những dòng tiếp theo mỗi dòng đưa vào một bộ test. 
    
    Mỗi bộ test là một biểu thức hậu tố exp. Các số xuất hiện 
    
    trong biểu thức là các số đơn có 1 chữ số.
Output:

    Đưa ra kết quả mỗi test theo từng dòng, 
    
    chỉ lấy giá trị phần nguyên.
Ràng buộc:

    T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.

Ví dụ:

Input               Output

2

231*+9–             -4

875*+9-             34

*/

#include <bits/stdc++.h>

using namespace std;

int calc(int a, int b, char c)
{
    if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else if (c == '*')
        return a * b;
    else if (c == '/')
        return a / b;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        cin >> s;
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                st.push(s[i] - '0');
            }
            else
            {
                int o1 = st.top();
                st.pop();
                int o2 = st.top();
                st.pop();
                int o3 = calc(o2, o1, s[i]);
                st.push(o3);
            }
        }
        cout << st.top() << "\n";
    }
}