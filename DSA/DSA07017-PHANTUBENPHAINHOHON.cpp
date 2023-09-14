
/*

    Cho mảng A[] gồm n phần tử. Hãy đưa ra các phần tử nhỏ hơn 
    
    tiếp theo của phần tử lớn hơn đầu tiên phần tử hiện tại. 
    
    Nếu phần tử hiện tại không có phần tử lớn hơn tiếp theo 
    
    ta xem là -1. Nếu phần tử không có phần tử nhỏ hơn tiếp theo 
    
    ta cũng xem là -1. Ví dụ với mảng A[] = {5, 1, 9, 2, 5, 1, 7} 
    
    ta có kết quả là ans = {2, 2, -1, 1, -1, -1, -1} vì:

Next Greater                        Right Smaller

5    ->  9                          9  ->  2

1    ->  9                          9  ->  2

9    -> -1                          -1 -> -1

2    -> 5                           5   -> 1

5    -> 7                           7  -> -1

1    ->  7                          7 -> -1

7    -> -1                          7 -> -1

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T;

    Những dòng tiếp theo mỗi dòng đưa vào một bộ test. 
    
    Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào n 
    
    là số phần tử của mảng A[], dòng tiếp theo đưa vào n số A[i].
Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ràng buộc:

    T, n, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤n, A[i] ≤106.

Ví dụ:

Input                       Output

2
7
5 1 9 2 5 1 7               2 2 -1 1 -1 -1 -1

8
4 8 2 1 9 5 6 3             2 5 5 5 -1 3 -1 -1

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

    int a[n];
    for (int &x : a)
        cin >> x;
    int b[n], c[n];
    stack<int> st1, st2; // lưu chỉ số
    // phan tu dau tien ben phai lon hon
    for (int i = 0; i < n; i++)
    {
        while (!st1.empty() && a[i] > a[st1.top()])
        {
            b[st1.top()] = i;
            st1.pop();
        }
        st1.push(i);
    }
    while (!st1.empty())
    {
        b[st1.top()] = -1;
        st1.pop();
    }
    // for(auto x : b) cout << x << " "; cout << "\n";
    // phan tu dau tien ben phai nho hon
    for (int i = 0; i < n; i++)
    {
        while (!st2.empty() && a[i] < a[st2.top()])
        {
            c[st2.top()] = i;
            st2.pop();
        }
        st2.push(i);
    }
    while (!st2.empty())
    {
        c[st2.top()] = -1;
        st2.pop();
    }
    // for(auto x : c) cout << x << " ";
    // cout << "\n";
    // c[b[i]] : chi so cua thang < thang lon hon dau tien cua a[i]
    for (int i = 0; i < n; i++)
    {
        if (b[i] != -1 && c[b[i]] != -1)
            cout << a[c[b[i]]] << " ";
        else
            cout << "-1 ";
    }
    cout << "\n";
}

signed main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int TEST = 1;
    cin >> TEST;
    for (int test = 1; test <= TEST; test++)
    {
        solve();
    }
}