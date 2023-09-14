
/*

    Cho hai số nguyên dương S và T (S, T<10000) và hai thao tác (a), (b) dưới đây:

    Thao tác (a): Trừ S đi 1  (S = S-1) ;

    Thao tác (b): Nhân S với 2 ( S = S*2);

    Hãy dịch chuyển S thành T sao cho số lần thực hiện 
    
    các thao tác (a), (b) là ít nhất. Ví dụ với S =2, T=5 thì 
    
    số các bước ít nhất để dịch chuyển S thành T thông qua 4 thao tác sau:

    Thao tác (a): 2*2 = 4;

    Thao tác (b): 4-1 = 3;

    Thao tác (a): 3*2 = 6;

    Thao tác (b): 6-1 = 5;

Input:

    Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;

    T dòng kế tiếp mỗi dòng ghi lại một bộ Test. 
    
    Mỗi test là một bộ đôi S và T.

Output: Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input               Output

3

2 5                 4

3 7                 4

7 4                 3

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

    int vs[10005] = {0};

    queue<pair<int, int>> Q;
    Q.push({n, 0});
    vs[n] = 1;

    while (Q.size())
    {
        auto x = Q.front();
        Q.pop();

        int Go1 = x.first;
        int coun = x.second;

        if (Go1 == 1)
        {
            cout << coun << "\n";
            return;
        }
        if (vs[Go1 - 1] == 0)
        {
            Q.push({Go1 - 1, coun + 1});
            vs[Go1 - 1] = 1;
        }
        for (int i = 2; i <= sqrt(Go1); i++)
        {
            if (Go1 % i == 0)
            {
                int tmp = max(i, Go1 / i);
                if (vs[tmp] == 0)
                {
                    Q.push({tmp, coun + 1});
                    vs[tmp] = 1;
                }
            }
        }
    }
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int TEST;
    cin >> TEST;
    for (int test = 1; test <= TEST; test++)
    {
        solve();
    }
}