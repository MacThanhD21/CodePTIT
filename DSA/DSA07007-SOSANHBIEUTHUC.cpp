
/*

    Cho P1, P2 là hai biểu thức đúng chỉ bao gồm các ký tự 
    
    mở ngoặc ‘(’ hoặc đóng ngoặc ‘)’ và các toán hạng in thường. 
    
    Nhiệm vụ của bạn là định xem P1 và P2 có giống nhau hay không.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T;

    Những dòng tiếp theo mỗi dòng đưa vào một bộ test. 
    
    Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào P1, dòng tiếp theo đưa vào P2.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ràng buộc:

    T, P thỏa mãn ràng buộc: 1≤T≤100; 1≤length(P) ≤100.

Ví dụ:

Input               Output

2
-(a+b+c)
-a-b-c              YES
a-b-(c-d)
a-b-c-d             NO

*/


#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, b) for (int i = 0; i < b; i++)
#define PER(i, b) for (int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 166
#define debugArr(...) 166
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;
const int LOG = 12;

void solve()
{
    string s;
    cin >> s;
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')')
        {
            auto pos = st.top();
            st.pop();
            if (pos - 1 >= 0 && s[pos - 1] == '-')
            {
                for (int j = pos + 1; j < i; j++)
                {
                    if (s[j] == '+')
                        s[j] = '-';
                    else if (s[j] == '-')
                        s[j] = '+';
                }
            }
        }
    }
    string t;
    cin >> t;
    stack<int> st2;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '(')
            st2.push(i);
        else if (t[i] == ')')
        {
            int x = st2.top();
            st2.pop();
            if (x - 1 >= 0 && t[x - 1] == '-')
            {
                for (int j = x + 1; j < i; j++)
                {
                    if (t[j] == '+')
                        t[j] = '-';
                    else if (t[j] == '-')
                        t[j] = '+';
                }
            }
        }
    }
    string u = "", v = "";
    for (auto x : s)
    {
        if (x != '(' && x != ')')
            u += string(1, x);
    }
    for (auto x : t)
    {
        if (x != '(' && x != ')')
            v += string(1, x);
    }
    if (u != v)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int TEST = 1;
    cin >> TEST;
    for (int test = 1; test <= TEST; test++)
    {
        solve();
    }
}