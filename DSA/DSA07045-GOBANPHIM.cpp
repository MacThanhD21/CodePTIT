

/*

    Trong quá trình gõ một dòng văn bản, chúng ta thường sử dụng phím sang trái, 
    
    sang phải hoặc xóa lùi (backspace). Cho một dãy ký tự mô tả các thao tác gõ phím, 
    
    trong đó:

    Ký tự ‘-’ mô tả phím backspace (xóa lùi). 
    
    Ký tự ở phía trước con trỏ (nếu có) sẽ bị xóa.

    Ký tự ‘<’ mô tả phím di chuyển sang trái. 
    
    Con trỏ sẽ sang trái 1 ký tự nếu có thể.

    Ký tự ‘>’ mô tả phím di chuyển sang phải. 
    
    Con trỏ sẽ sang phải 1 ký tự nếu có thể.

    Các ký tự khác là các chữ cái Tiếng Anh 
    
    (in hoa hoặc in thường). Bàn phím để ở chế độ Insert. 
    
    Tức là nếu con trỏ không ở cuối dòng thì khi chèn 
    
    các ký tự sẽ đẩy các ký tự khác sang phải một vị trí.

    Hãy thử tính toán và viết ra kết quả tương ứng.

Input

    Có một dòng không quá 106 ký tự mô tả dãy gõ bàn phím.

Output

    Ghi ra kết quả.

Ví dụ

Input               Output

<<PI<T>>Ta-         PTIT

*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

void solve(string s)
{
    stack<char> X, Y;
    for (char x : s)
    {
        if (x == '<')
        {
            if (X.size())
            {
                Y.push(X.top());
                X.pop();
            }
        }
        else if (x == '>')
        {
            if (Y.size())
            {
                X.push(Y.top());
                Y.pop();
            }
        }
        else if (x == '-')
        {
            if (X.size())
            {
                X.pop();
            }
        }
        else
            X.push(x);
    }
    while (X.size())
    {
        Y.push(X.top());
        X.pop();
    }
    while (Y.size())
    {
        cout << Y.top();
        Y.pop();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    solve(s);
    return 0;
}