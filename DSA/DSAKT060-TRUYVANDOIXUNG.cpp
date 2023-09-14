

/*

    Cho số nguyên S gồm N chữ số. Có Q truy vấn, mỗi truy vấn 
    
    thuộc một trong hai loại sau:

    q L R: yêu cầu xác định xâu con S[L, L+1, …, R] có phải 
    
    là một xâu đối xứng hay không?

    c U x: thay đổi kí tự thứ U thành chữ số x.

Input

    Dòng đầu tiên chứa số nguyên S gồm N kí tự (N  <= 10^5).

    Tiếp theo là số lượng truy vấn Q (Q <= 10^5)

    Q dòng tiếp theo, mỗi dòng gồm một loại truy vấn.

Output

    Với mỗi truy vấn loại 1, nếu xâu con là một số đối xứng, 
    
    hãy in ra “YES”, ngược lại in ra “NO”.
Ví dụ:

Input               Output

12345

5

q 1 5               NO

q 5 5               YES

c 4 3

q 3 5               NO

q 3 4               YES

*/

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define F(i, a, b) for (int i = a; i < b; ++i)
#define FD(i, a, b) for (int i = a; i > b; --i)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n, q;
string s;
const int N = 1e5 + 5, Prime = 17;
ll Pow[N], Fenwick1[N], Fenwick2[N];

inline void Update(int idx, int x)
{
    ll val = Pow[idx] * x;
    for (int i = idx; i <= n; i += (i & -i))
        Fenwick1[i] += val;
    val = Pow[n - idx + 1] * x;
    while (idx)
    {
        Fenwick2[idx] += val;
        idx -= (idx & -idx);
    }
}

inline ll Get1(int idx)
{
    ll res = 0;
    while (idx)
    {
        res += Fenwick1[idx];
        idx -= (idx & -idx);
    }
    return res;
}

inline ll Get2(int idx)
{
    ll res = 0;
    while (idx <= n)
    {
        res += Fenwick2[idx];
        idx += (idx & -idx);
    }
    return res;
}
int main()
{
    faster();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> s >> q;
        n = s.sz;
        s = "*" + s;
        Pow[0] = 1;
        for (int i = 1; i <= n; ++i)
            Pow[i] = Pow[i - 1] * Prime;
        for (int i = 1; i <= n; ++i)
            Update(i, s[i]);
        int l, r;
        char c, x;
        while (q--)
        {
            cin >> c;
            if (c == 'c')
            {
                cin >> l >> x;
                Update(l, x - s[l]);
                s[l] = x;
            }
            else
            {
                cin >> l >> r;
                if (((Get1(r) - Get1(l - 1)) * Pow[n - r + 1] == (Get2(l) - Get2(r + 1)) * Pow[l]))
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
    return 0;
}