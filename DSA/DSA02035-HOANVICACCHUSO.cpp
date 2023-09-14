
/*

    Độ chênh lệch của một dãy số nguyên dương được định nghĩa 
    
    là hiệu của số lớn nhất trừ đi số nhỏ nhất trong dãy.

    Cho hai số nguyên dương n và k, với 1 <= n, k <= 8.

    Với n xâu ký tự số có độ dài k, có thể có chữ số 0 ở đầu. 
    
    Hãy tìm cách duyệt tất cả hoán vị các chữ số của từng số trong 
    
    danh sách sao cho độ chênh lệch của dãy số tạo được là bé nhất có thể.

Input

    Dòng đầu ghi hai số n và k.

    Tiếp theo là n dòng, mỗi dòng ghi một xâu ký tự đúng k chữ số.

Output

    Ghi ra độ chênh lệch bé nhất có thể.

Ví dụ

Input               Output

6 4                 2700
5237
2753
7523
5723
5327
2537


3 3                 3
010
909
012

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
    int n, k;
    cin >> n >> k;
    vector<string> S(n);
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    vector<int> A;
    // vector<int> A(k); // nếu để số lượng phần tử thì nó như mảng, push vào toàn 0 => sai

    // A : hoan vi chi số
    iota(all(A), 0); // 0 1 2 3
    for (int u = 0; u < k; u++)
    {
        A.push_back(u);
    }
    // for(auto x : A) cout << x << " ";

    int res = INT_MAX;

    do
    {
        int minn = INT_MAX, maxx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            string s = "";
            for (int j = 0; j < k; j++)
            {
                s += S[i][A[j]];
            }
            int tmp = stoi(s);
            // cout << tmp << "\n";
            minn = min(minn, tmp);
            maxx = max(maxx, tmp);
        }
        res = min(res, maxx - minn);

    } while (next_permutation(A.begin(), A.end()));
    cout << res << "\n";
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