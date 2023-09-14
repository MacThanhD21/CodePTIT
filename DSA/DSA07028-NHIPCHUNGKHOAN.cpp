
/*

    Bạn là một nhà đầu tư chứng khoán nổi tiếng. Nhiệm vụ hàng ngày 
    
    của bạn là tính nhịp tăng giảm của phiên chứng khoán trong N ngày
    
    để có thể bắt kịp thị trường. Nhịp chứng khoán của ngày thứ i 
    
    được định nghĩa là số ngày liên tiếp từ ngày thứ i trở về mà giá 
    
    chứng khoán bé hơn hoặc bằng với giá chứng khoán của ngày i.

Input: 

    Dòng đầu ghi số bộ test (không quá 10). Mỗi test có 2 dòng.

    Dòng đầu tiên gồm 1 số nguyên N (1 ≤ N ≤ 105) là số ngày.

    Dòng tiếp theo gồm N số nguyên A1, A2, …, AN (1 ≤ Ai ≤ 106) 
    
    là giá chứng khoán của các ngày.

Output

    In ra N số B1, B2, …, BN trong đó Bi 
    
    là nhịp chứng khoán của ngày thứ i.
Ví dụ:

Input                       Output

1

7

100 80 60 70 60 75 85       1 1 1 2 1 4 6

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
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    stack<int> st;

    // tim khoang cach giua vi tri hien tai voi phan tu ben trai dau tien lon hon

    for (int i = n; i >= 1; --i)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            b[st.top()] = st.top() - i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        b[st.top()] = st.top();
        st.pop();
    }
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
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