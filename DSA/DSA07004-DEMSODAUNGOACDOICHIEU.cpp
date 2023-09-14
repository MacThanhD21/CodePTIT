
/*

    Cho một xâu chỉ gồm các kí tự ‘(‘, ‘) và có độ dài chẵn.

    Hãy đếm số lượng dấu ngoặc cần phải đổi chiều ít nhất,

    sao cho xâu mới thu được là một dãy ngoặc đúng.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm 1 xâu S có độ dài không vượt quá 100 000,

    chỉ gồm dấu ( và ).

Output:

    Với mỗi test, in ra đáp án tìm được trên một dòng.

Ví dụ:

Input               Output

4

))((                2

((((                2

(((())              1

)(())(((            3

*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

#define ll long long

void solve()
{
    string s;
    cin >> s;
    int open, close;
    open = close = 0;
    stack<char> st;
    for (auto x : s)
    {
        if (x == '(')
        {
            ++open;
            st.push(x);
        }
        else if (x == ')')
        {
            if (st.size() && st.top() == '(')
            {
                st.pop();
                --open;
            }
            else
            {
                st.push(x);
                ++close;
            }
        }
    }
    int ans = open / 2 + close / 2;
    ans += open % 2 + close % 2;
    cout << ans << "\n";
}

int main()
{
    int T = 1;
    cin >> T;

    while (T--)
    {
        solve();
    }
}