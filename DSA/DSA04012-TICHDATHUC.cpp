
/*

    Cho hai đa thức P và Q được biểu diễn như một mảng bao gồm 
    
    các hệ số của đa thức. Ví dụ với P(x) = 5 + 0x1 +10x2 + 6x3 được 
    
    biểu diễn như mảng P[] ={5, 0, 10, 6}. Hãy đưa ra đa thức R = P×Q 
    
    theo các hệ số của R với cách biểu diễn như trên.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào 
    
    hai số M, N tương ứng với lũy thừa lớn nhất của 
    
    đa thức P và Q; dòng tiếp theo đưa vào M số là hệ số của đa thức P; 
    
    dòng cuối cùng đưa vào M số là hệ số của đa thức Q.

    T, M, N, P[i], Q[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤M, N≤100; 1≤P[i], Q[i]≤100.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
    
Ví dụ:

Input               Output

2
4 3
1 0 3 2             2 0 10 4 12 8
2 0 4               4 36 14 39 79 23 34 35
5 4
1 9 3 4 7
4 0 2 5
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
    int n, m;
    cin >> n >> m;
    int a[n], b[m], res[m + n - 1] = {0};

    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res[i + j] += a[i] * b[j];
        }
    }
    for (auto x : res)
        cout << x << " ";
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