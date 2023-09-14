

/*

    Cho một cây biểu thức là một cây nhị phân đầy đủ bao gồm các phép toán 

    +, -, *. / và một số toán hạng có giá trị nguyên. Nhiệm vụ của bạn là 

    hãy tính toán giá trị biểu thức được biểu diễn trên cây nhị phân đầy đủ. 

    Ví dụ với cây dưới đây là biểu diễn của biểu thức P = ((5*4) + (100-20)) 

    sẽ cho ta giá trị là 100.

    C:\Users\ADMIN\Downloads\download (8).png

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test là gồm hai dòng: dòng thứ nhất đưa vào 
    
    N là số lượng node của cây; dòng thứ hai đưa vào nội dung 
    
    các node của cây; các node được viết cách nhau một vài khoảng trống. 
    
    Các số có giá trị nguyên không vượt quá 1000.

    T, N, P thỏa mãn ràng buộc : 1≤T≤100; 1≤N, lenght(P)≤100.

Output:

    Đưa ra giá trị của cây biểu thức.
Ví dụ:

Input                       Output

2
7
+ * - 5 4 100 20            100
3
- 4 7                       -3

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    string s[1005];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    queue<ll> Q;
    for (int i = n - 1; i >= 0; i--)
    {
        if (isdigit(s[i][0]))
        {
            Q.push(stoll(s[i]));
        }
        else
        {
            ll x2 = Q.front();
            Q.pop();
            ll x1 = Q.front();
            Q.pop();

            if (s[i] == "+")
            {
                Q.push(x1 + x2);
            }
            if (s[i] == "-")
            {
                Q.push(x1 - x2);
            }
            if (s[i] == "*")
            {
                Q.push(x1 * x2);
            }
            if (s[i] == "/")
            {
                Q.push(x1 / x2);
            }
        }
    }
    cout << Q.front() << "\n";
    ;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}