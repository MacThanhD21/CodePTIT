

/*

    Cho biểu thức toán học đúng, bạn cần tìm tất cả các biểu thức đúng 
    
    có thể bằng cách xóa bỏ các cặp dấu ngoặc tương ứng với nhau từ biểu thức ban đầu.

    Ví dụ: Cho biểu thức: (2+(2*2)+2) Các biểu thức tìm được:

    (2+2*2+2)

    2+(2*2)+2

    2+2*2+2

    Các biểu thức (2+2*2)+2 và 2+(2*2+2) không được chấp nhận 
    
    vì không xóa đi các cặp dấu ngoặc tương ứng với nhau

Input: 

    Một dòng chứa biểu thức gồm các số nguyên không âm, 
    
    các dấu +, -, *, / và dấu ngoặc đơn.

    Biểu thức không quá 200 kí tự, có chứa ít nhất 
    
    1 và không quá 10 cặp dấu ngoặc.

Output: 

    In ra tất các các biểu thức khác nhau 
    
    thỏa mãn đầu bài theo thứ tự từ điển

Ví dụ

Input                   Output

(1+(2*(3+4)))           (1+(2*3+4))
                        (1+2*(3+4))
                        (1+2*3+4)
                        1+(2*(3+4))
                        1+(2*3+4)
                        1+2*(3+4)
                        1+2*3+4

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

set<string> se;
queue<string> L;
stack<string> st1;

void Delete(string s)
{
    vector<pii> v;
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            v.push_back({st.top(), i});
            st.pop();
        }
    }
    for (auto x : v)
    {
        string tmp = s;
        tmp.erase(x.first, 1);
        tmp.erase(x.second - 1, 1);

        if (se.count(tmp) == 0)
        {
            se.insert(tmp);
            st1.push(tmp);
        }
    }
}

void solve()
{
    string s;
    cin >> s;
    st1.push(s);
    while (st1.size())
    {
        string top = st1.top();
        st1.pop();
        Delete(top);
    }

    for (auto v : se)
    {
        cout << v << "\n";
    }
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int TEST = 1;
    // cin >> TEST;
    for (int test = 1; test <= TEST; test++)
    {
        solve();
    }
}