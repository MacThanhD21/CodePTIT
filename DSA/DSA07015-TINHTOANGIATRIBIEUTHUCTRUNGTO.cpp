
/*

    Cho biểu thức trung tố S với các toán tử +, -, *, / và dấu ngoặc (). 
    
    Các toán hạng là các số có giá trị không vượt quá 100. 
    
    Hãy tính giá trị biểu thức S. Phép chia thực hiện với số nguyên, 
    
    input đảm bảo số bị chia luôn khác 0, đáp số biểu thức có không quá 10 chữ số.

Input:

    Dòng đầu tiên là số lượng bộ test (T ≤ 100).

    Mỗi dòng gồm một xâu S, không quá 100 kí tự. 
    
    Các toán hạng là các số nguyên không âm.

Output: 

    Với mỗi test, in ra đáp án tìm được.

Ví dụ:

Input                   Output

4

6*3+2-(6-4/2)           16

100+99*22               2278

6*((4*3)+5)             102

1-2                     -1

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

int prioritize(char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}

ll calc(ll a, ll b, char c)
{
    if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else if (c == '*')
        return a * b;
    else
        return a / b;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    stack<ll> val;    // lưu giá trị
    stack<char> oper; // lưu toán hạng + - * /

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            oper.push(s[i]);
        }
        else if (isdigit(s[i]))
        {
            ll val ue = 0;
            while (i < n && isdigit(s[i]))
            {
                value = value * 10 + (s[i] - '0');
                ++i;
            }
            // i : dang ở dấu tiếp theo, phải trừ đi 1 để for chạy đến
            val.push(value);
            --i; // 100 quay ve 0, vì for cũng +1
        }
        else if (s[i] == ')')
        {
            while (!oper.empty() && oper.top() != '(')
            {
                ll val2 = val.top();
                val.pop();
                ll val1 = val.top();
                val.pop();

                char c = oper.top();
                oper.pop();

                val.push(calc(val1, val2, c));
            }
            oper.pop();
        }
        else
        {
            while (!oper.empty() && prioritize(oper.top()) >= prioritize(s[i]))
            {
                ll val2 = val.top();
                val.pop();
                ll val1 = val.top();
                val.pop();
                char c = oper.top();
                oper.pop();
                val.push(calc(val1, val2, c));
            }
            oper.push(s[i]);
        }
    }
    while (!oper.empty())
    {
        ll val2 = val.top();
        val.pop();
        ll val1 = val.top();
        val.pop();
        char c = oper.top();
        oper.pop();
        val.push(calc(val1, val2, c));
    }
    cout << val.top() << "\n";
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