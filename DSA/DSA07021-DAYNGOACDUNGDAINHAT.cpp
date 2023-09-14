

/*

    Cho một xâu chỉ gồm các kí tự ‘(‘ và ‘)’.

    Một dãy ngoặc đúng được định nghĩa như sau:

    -     Xâu rỗng là 1 dãy ngoặc đúng.

    -     Nếu A là 1 dãy ngoặc đúng thì (A) là 1 dãy ngoặc đúng.

    -     Nếu A và B là 2 dãy ngoặc đúng thì AB là 1 dãy ngoặc đúng.

    Cho một xâu S. Nhiệm vụ của bạn là hãy tìm dãy ngoặc đúng dài nhất xuất hiện trong xâu đã cho.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm một xâu S có độ dài không vượt quá 105 kí tự.

Output:

    Với mỗi test in ra một số nguyên là

    độ dài dãy ngoặc đúng dài nhất tìm được.

Ví dụ:

Input               Output

3

((()                2

)()())              4

()(()))))           6

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
    int l = 0, r = 0, ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            l++;
        else
            r++;
        if (l == r)
            ans = max(ans, 2 * r);
        if (r > l)
            l = 0, r = 0;
    }
    l = 0, r = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
            l++;
        else
            r++;
        if (l == r)
            ans = max(ans, 2 * r);
        if (r < l)
            l = 0, r = 0;
    }
    cout << ans << "\n";
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

// CACH 2:

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

// Note : Day ngoac dung dai nhat KHONG lien tiep

void solve()
{
    string s;
    cin >> s;
    stack<int> st;
    st.push(-1);
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);

        else if (s[i] == ')')
        {
            st.pop();
            if (!st.size())
            {
                st.push(i); // vi tri dau ")", tuong tu nhu -1 (ao ma vcl)
            }
            else
            {
                ans = max(ans, i - st.top()); // khong pop (ao ma part 2)
            }
        }
    }
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