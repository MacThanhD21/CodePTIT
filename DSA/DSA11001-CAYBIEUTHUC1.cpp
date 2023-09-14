

/*

    Cây biểu thức là một cây nhị phân trong đó mỗi node trung gian 

    là một phép toán, mỗi node lá là một toán hạng. Ví dụ với biểu thức 

    P = 3 + ((5+9)*2) sẽ được biểu diễn như cây dưới đây.

    C:\Users\ADMIN\Downloads\download (7).png


    Đối với cây biểu thức, duyệt theo thứ tự trước ta sẽ được 
    
    biểu thức tiền tố, duyệt theo thứ tự sau ta sẽ được biểu thức 
    
    hậu tố, duyệt theo thứ tự giữa ta được biểu thức trung tố. 
    
    Chú ý, cây biểu thức luôn là cây nhị phân đầy (mỗi node trung gian đều có hai node con).

    Cho biểu thức hậu tố P, hãy sử dụng cây biểu thức để đưa ra 
    
    biểu thức trung tố tương ứng với biểu thức P.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test là một biểu thức hậu tố P.

    T, P thỏa mãn ràng buộc : 1≤T≤100; 1≤lengh(P)≤100.
Output:

    Đưa ra biểu thức trung tố tương ứng với P.
Ví dụ:

 

Input               Output

2
ab+ef*g*-           a+b-e*f*g
wlrb+-*             w*l-r+b


*/

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    stack<string> st;
    for (auto x : s)
    {
        if (isalpha(x))
        {
            st.push(string(1, x));
        }
        else
        {
            string s2 = st.top();
            st.pop();
            string s1 = st.top();
            st.pop();

            st.push(s1 + x + s2);
        }
    }
    cout << st.top() << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}