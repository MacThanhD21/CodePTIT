

/*

    Cho số nguyên dương N và K. Hãy tính NK modulo 10^9+7.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm 1 số nguyên N và K (1 ≤ N ≤ 1000, 1 ≤ K ≤ 109).

Output: 

    Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input           Output

2

2 3             8

4 2             16

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO()                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pb push_back

const int mod = 1e9 + 7;

vector<int> adj[1005];
bool visited[1005];
int trace[1005];

ll powMod(ll a, ll b)
{
    ll res = 1;
    while (b != 0)
    {
        if (b & 1)
        {
            res = ((res % mod) * (a % mod)) % mod;
        }
        a = ((a % mod) * (a % mod)) % mod;
        b /= 2;
    }
    return res;
}

int main()
{
    IO();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << powMod(n, k) << "\n";
    }
}


/*

mod = 10**9 + 7

def powMod(a, b):
    res = 1
    while b != 0:
        if b & 1:
            res = (res * a) % mod
        a = (a * a) % mod
        b //= 2
    return res

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    result = powMod(n, k)
    print(result)


*/