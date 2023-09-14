
/*


    Cho biểu thức đúng P chỉ bao gồm các phép toán +, -, 
    
    các toán hạng cùng với các ký tự ‘(’, ‘)’. Hãy bỏ tất cả 
    
    các ký tự ‘(’, ‘)’ trong P để nhận được biểu thức tương đương. 
    
    Ví dụ với P = a – (b + c) ta có kết quả P = a – b – c .

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T;

    Những dòng tiếp theo mỗi dòng đưa vào một bộ test. 
    
    Mỗi bộ test là một biểu thức P được viết trên một dòng.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ràng buộc:

    T, P thỏa mãn ràng buộc: 1≤T≤100; 1≤length(P)≤103.
Ví dụ:

Input                   Output

2
a–(b+c)                 a-b-c
a-(b-c-(d+e))-f         a-b+c+d+e-f

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
                for (int j = pos + 1; j < i; j++) // i là vị trí của dấu đóng ngoặc : xử lý từng cặp trong từng cặp dấu.
                {
                    if (s[j] == '+')
                        s[j] = '-';
                    else if (s[j] == '-')
                        s[j] = '+';
                }
            }
        }
    }
    for (auto x : s)
    {
        if (x != '(' && x != ')')
            cout << x;
    }
    cout << "\n";
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