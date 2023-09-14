
/*

    Cho xâu ký tự mã hóa str. Hãy viết chương trình giải mã xâu ký tự str. 
    
    Xâu ký tự mã hóa được thực hiện theo số lần lặp các xâu con của str như sau:

    Xâu đầu vào: “abbbababbbababbbab ”

    Xâu mã hóa : "3[a3[b]1[ab]]"

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T;

    Những dòng tiếp theo mỗi dòng đưa vào một bộ test. 
    
    Mỗi bộ test là một xâu mã hóa str được viết trên một dòng.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.
    
Ràng buộc:

    T, str thỏa mãn ràng buộc: 1≤T≤100; 1≤length(str)≤100.

Ví dụ:

Input               Output

2
1[b]                b
3[b2[ca]]           bcacabcacabcaca

*/


#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

inline void solve()
{
    string s;
    cin >> s;
    stack<string> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        {
            string res;
            for (int j = i; j < n; j++)
            {
                if (isdigit(s[j]))
                    res += s[j], i = j;
                else
                    break;
            }
            st.push(res);
        }
        else if (isalpha(s[i]))
        {
            string res;
            for (int j = i; j < n; j++)
            {
                if (isalpha(s[j]))
                    res += s[j], i = j;
                else
                    break;
            }
            st.push(res);
        }
        else if (s[i] == '[')
            st.push("[");
        else
        {
            vector<string> res;
            while (st.top() != "[")
            {
                auto x = st.top();
                st.pop();
                res.push_back(x);
            }
            st.pop();
            reverse(res.begin(), res.end());
            string ans;
            for (auto x : res)
                ans += x;
            string tds;
            if (st.size() && isdigit(st.top()[0]))
            {
                int tmp = stoi(st.top());
                while (tmp--)
                    tds += ans;
                st.pop();
                st.push(tds);
            }
            else
                st.push(ans);
        }
    }
    vector<string> ans;
    while (st.size())
        ans.push_back(st.top()), st.pop();
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}