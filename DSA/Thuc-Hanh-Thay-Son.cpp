
// Dau ngoac đúng liên tiếp dài nhất, in ra số lượng dấu '[' lớn nhất
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    stack<pair<char, int>> st;
    vector<int> b(n + 2, 0);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[')
            st.push({s[i], i});
        else
        {
            if (s[i] == ')')
            {
                if (!st.empty() && st.top().first == '(')
                    st.pop();
                else
                {
                    b[i] = -1;
                    while (!st.empty())
                    {
                        b[st.top().second] = -1;
                        st.pop();
                    }
                }
            }
            else
            {
                if (!st.empty() && st.top().first == '[')
                {
                    b[i] = 1;
                    st.pop();
                }
                else
                {
                    b[i] = -1;
                    while (!st.empty())
                    {
                        b[st.top().second] = -1;
                        st.pop();
                    }
                }
            }
        }
    }

    int ans = 0, cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == -1)
            cur = 0;
        else
            cur += b[i];
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}

// 1. DINH TRU CANH CAU
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>

int n, m, timer = 0, cnt = 0, ans = 0;
vector<int> v[1005];
int low[1005], disc[1005];
bool vertex[1005], used[1005];
void dfs(int u, int par)
{
    disc[u] = low[u] = ++timer;
    int child = 0;
    for (auto x : v[u])
    {
        if (!disc[x])
        {
            child++;
            dfs(x, u);
            low[u] = min(low[u], low[x]);
            if (low[x] >= disc[u] && par != -1)
                vertex[u] = true;
        }
        else
            low[u] = min(low[u], disc[x]);
    }
    if (child >= 2 && par == -1)
        vertex[u] = true;
}
void dfs2(int u, int par)
{
    used[u] = 1;
    disc[u] = low[u] = ++timer;
    for (int x : v[u])
    {
        if (x == par)
            continue;
        if (!used[x])
        {
            dfs2(x, u);
            low[u] = min(low[u], low[x]);
            if (low[x] > disc[u])
                ans++;
        }
        else
        {
            low[u] = min(low[u], disc[x]);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(disc, 0, sizeof(disc));
    dfs(1, -1);
    for (int i = 1; i <= n; i++)
        if (vertex[i])
            cnt++;
    cout << cnt << " ";
    timer = 0;
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            dfs2(i, -1);
        }
    }
    cout << ans;
}

// 2.KHONG LIEN THONG VOI DINH 1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int n, m;
vector<int> v[1005];
bool used[1005];
void dfs(int u)
{
    used[u] = true;
    for (auto x : v[u])
        if (!used[x])
            dfs(x);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    int ok = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
            cout << i << endl, ok = 1;
    }
    if (!ok)
        cout << 0 << endl;
}
//

// 3.DUONG DI
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int n, m, s, t;
vector<int> v[1005];
bool used[1005];
int way[1005];
void solve()
{
    for (int i = 0; i <= 1003; i++)
        v[i].clear();
    memset(used, false, sizeof(used));
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }
    queue<int> q;
    q.push(s);
    used[s] = true;
    way[s] = -1;
    while (q.size())
    {
        auto x = q.front();
        q.pop();
        if (x == t)
        {
            break;
        }
        for (auto j : v[x])
        {
            if (!used[j])
            {
                used[j] = true;
                q.push(j);
                way[j] = x;
            }
        }
    }
    stack<int> st;
    if (!used[t])
        cout << -1 << endl;
    else
    {
        st.push(t);
        t = way[t];
        while (t != -1)
            st.push(t), t = way[t];
        while (st.size())
            cout << st.top() << " ", st.pop();
        cout << endl;
    }
}
int main({
    int t;
    cin >> t;
    while (t--)
        solve();
	
}
//

// 4.SO BUOC DI CHUYEN IT NHAT
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int n , m;
int a[1005][1005];
bool used[1005][1005];
int bfs(int u , int v){
    queue<pair<ii, int>> q;
    q.push({{u, v}, 0});
    used[u][v] = true;
    while (q.size())
    {
        auto x = q.front();
        q.pop();
        auto x1 = x.first;
        auto x2 = x.second;
        int i = x1.first, j = x1.second;
        if (i == n && j == m)
            return x2;
        int val1 = -123456, val2 = -123456, val3 = -123456;
        if (i + 1 <= n)
            val1 = abs(a[i][j] - a[i + 1][j]);
        if (j + 1 <= m)
            val2 = abs(a[i][j] - a[i][j + 1]);
        if (i + 1 <= n && j + 1 <= m)
            val3 = abs(a[i][j] - a[i + 1][j + 1]);
        if (val1 != -123456 && val1 >= 0 && i + val1 <= n && i + val1 >= 1 && !used[i + val1][j])
            used[i + val1][j] = true, q.push({{i + val1, j}, x2 + 1});
        if (val2 != -123456 && val2 >= 0 && j + val2 <= m && j + val2 >= 1 && !used[i][j + val2])
            used[i][j + val2] = true, q.push({{i, j + val2}, x2 + 1});
        if (val3 != -123456 && val3 >= 0 && i + val3 <= n && j + val3 <= m && i + val3 >= 1 && j + val3 >= 1 && !used[i + val3][j + val3])
            used[i + val3][j + val3] = true, q.push({{i + val3, j + val3}, x2 + 1});
    }
    return -1;
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    cout << bfs(1, 1) << endl;
    memset(used, false, sizeof(used));
}
int main(){
    int t;
    t = 1;
    cin >> t;
    while (t--)
        solve();
}
// 5. THI NGHIEM VAT Li
#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> mirrorlist;

int main(){
    int n;
    int xA, yA, xB, yB;
    cin >> n >> xA >> yA >> xB >> yB;
    mirrorlist.clear();
    mirrorlist.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        mirrorlist[a].push_back(b);
    }
    queue<pair<int, int>> qu;
    // Gia su ban dau di truc Oy
    qu.push({xA, 0});
    while (!qu.empty())
    {
        pair<int, int> tmp = qu.front();
        if (tmp.first == xB || tmp.first == yB)
        {
            cout << tmp.second << endl;
            break;
        }
        for (auto x : mirrorlist[tmp.first])
        {
            qu.push({x, tmp.second + 1});
        }
        qu.pop();
    }
    return 0;
}
// HINH CHU NHAT LON NHAT
#include <bits/stdc++.h>
using namespace std;
int a[1000005] ;
#define ll long long
int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m], b[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (!a[i][j])
                b[i][j] = 0;
            else if (i == 0)
                b[i][j] = 1;
            else
                b[i][j] = b[i - 1][j] + 1;
        }
    }
    int ans = 0;
    for (int k = 0; k < n; k++)
    {
        //
        stack<int> st;
        for (int i = 0; i < m; i++)
        {
            while (st.size() && b[k][i] < b[k][st.top()])
            {
                int x = st.top();
                st.pop();
                if (!st.size())
                    ans = max(ans, b[k][x] * i);
                else
                    ans = max(ans, b[k][x] * (i - 1 - st.top()));
            }
            st.push(i);
        }
        int tmp = 0;
        while (st.size() && tmp < b[k][st.top()])
        {
            int x = st.top();
            st.pop();
            if (!st.size())
                ans = max(ans, b[k][x] * m);
            else
                ans = max(ans, b[k][x] * (m - 1 - st.top()));
        }
    }
    cout << ans;
}
// segment
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll n , q;
ll t[1000000 * 4  + 1];
ll a[1000005];
void sinh(ll u ,ll l , ll r){
    if (l == r)
        t[u] = a[l];
    else
    {
        ll m = (l + r) / 2;
        sinh(2 * u, l, m);
        sinh(2 * u + 1, m + 1, r);
        t[u] = min(t[2 * u], t[2 * u + 1]);
    }
}
int query(int u ,int tl , int tr , int l , int r){
    if (l == tl && r == tr)
        return t[u];
    else
    {
        int tm = (tl + tr) / 2;
        if (l > tm)
            return query(2 * u + 1, tm + 1, tr, l, r); // l va r nam ben phai
        else if (r <= tm)
            return query(2 * u, tl, tm, l, r);                                            // l va r nam ben trai
        return min(query(2 * u, tl, tm, l, tm), query(2 * u + 1, tm + 1, tr, tm + 1, r)); // l va r nam vua trai vua phai
    }
}
void solve(){
    cin >> n >> q;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sinh(1, 0, n - 1);
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << query(1, 0, n - 1, l - 1, r - 1) << endl;
    }
}
int main(){
    solve();
}

// loai bo ngoac
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string a;
        getline(cin, a);
        stack<char> st;
        // ngooac viet la chi so, khong viet la ()
        string s;
        for (auto c : a)
        {
            if (c != ' ')
                s.push_back(c);
        }
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0 && s[i] == '(')
            {
                st.push('(');
            }
            else if (i != 0 && s[i] == '(')
            {
                if (s[i - 1] == '-')
                {
                    st.push('@');
                    res.push_back(s[i]);
                }
                else
                {
                    st.push(s[i]);
                }
            }

            else if (s[i] == ' ')
                continue;
            else if (s[i] == ')')
            {
                if (st.top() == '@')
                    cout << ')';
                st.pop();
            }
            else
            {
                res.push_back(s[i]);
            }
        }
        s = res;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' && s[i + 2] == ')')
            {
                s[i] = '@';
                s[i + 2] = '@';
            }
        }
        for (auto c : s)
        {
            if (c != '@')
                cout << c;
        }
        cout << endl;
    }
    return 0;
}



// bieu thuc tang giam
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Test " << i << ": ";
        string s;
        cin >> s;
        stack<int> st;

        for (int i = 0; i <= s.size(); i++)
        {
            st.push(i + 1);
            if (s[i] == 'I' || i == s.size())
            {
                while (!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
            }
            else if (s[i] == 'D')
            {
                if (i == s.size())
                {
                    while (!st.empty())
                    {
                        cout << st.top();
                        st.pop();
                    }
                }
            }
        }
        cout << "\n";
    }
}

// số may mắn
#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solution()
{
    // int a, b; cin >> a >> b;

    queue<ll> Q;
    Q.push(4);
    Q.push(7);
    vector<ll> v;
    ll res[150];

    while (1)
    {
        ll u = Q.front();
        v.push_back(u);
        if (u >= 1e9)
            break;
        Q.pop();

        Q.push(u * 10 + 4);
        Q.push(u * 10 + 7);
    }
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        for (auto it : v)
        {
            if (it >= i)
            {
                res[i] = it;
                break;
            }
        }
    }

    ll sum = 0;
    for (int i = a; i <= b; i++)
    {
        sum += res[i];
    }
    cout << sum << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solution();
}
// cách 2 nếu cách trên sai Số may mắn

#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
using ii = pair<int, int>;
#define MAX 1005
#define INF 0x3f3f3f
const int MOD = 1e9 + 7;
const int LIM = 4444444444;

vector<int> nums;
void prepare()
{
    queue<int> q;
    q.push(4);
    q.push(7);

    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        if (x > LIM)
            break;
        nums.push_back(x);
        q.push(x * 10 + 4);
        q.push(x * 10 + 7);
    }
    sort(nums.begin(), nums.end());
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    prepare();
    int a, b;
    cin >> a >> b;
    int cur = a;
    ll ans = 0;
    for (; cur < b;)
    {
        auto iter = lower_bound(nums.begin(), nums.end(), cur);
        int nxt = *iter;
        // cout << nxt << "\n";
        if (nxt >= b)
            break;
        int cnt = (nxt - cur + 1);
        ans += 1ll * cnt * nxt;
        cur = nxt + 1;
    }
    // cout << ans << " " << cur << "\n";
    auto iter = lower_bound(nums.begin(), nums.end(), cur);
    int nxt = *iter;
    int cnt = (b - cur + 1);
    ans += 1ll * cnt * nxt;

    cout << ans << "\n";
}

// Đỉnh Thắt

#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
vector<int> adj[1005];
bool used[1005];
vector<string> res;

void dfs(int u, string ans)
{
    used[u] = true;
    
    for (auto x : adj[u])
    {
        if (!used[x])
        {
            dfs(x, ans + to_string(x));
            used[x] = false;
            if (x == v)
            {
                ans += to_string(v);
                res.push_back(ans);
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> u >> v;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        used[i] = false;
    }
    res.clear();
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    dfs(u, to_string(u));

    // cout << res.size() << " ";

    int fre[1005] = {0};

    for (auto x : res)
    {
        for (auto z : x)
        {
            string tmp = "";
            tmp += z;
            z = stoi(tmp);
            fre[z]++;
        }
    }

    int anss = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i != u && i != v)
        {
            if (fre[i] == res.size())
            {
                ++anss;
                // cout << i << " " << fre[i] << "\n";
            }
        }
    }
    cout << anss << "\n";
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
