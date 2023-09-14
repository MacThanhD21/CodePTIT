

/*

    Cho mảng A[]  gồm n phần tử. Nhiệm vụ của bạn là tìm phần tử gần nhất 
    
    phía bên phải có số lần xuất hiện lớn hơn phần tử hiện tại. 
    
    Nếu không có phần tử nào có số lần xuất hiện lớn hơn phần tử 
    
    hiện tại hãy đưa ra -1.

    Ví dụ với dãy A[] = {1, 1, 2, 3, 4, 2, 1 }, ta nhận được kết quả 
    
    ans[] = {-1, -1, 1, 2, 2, 1, -1} vì số lần xuất hiện mỗi phần tử 
    
    trong mảng là F = {3, 3, 2, 1, 1, 2, 3} vì vậy phần tử A[0] = 1 có 
    
    số lần xuất hiện là 3 và không có phần tử nào xuất hiện nhiều hơn 3 
    
    nên ans[0] = -1, tương tự như vậy với A[2]=2 tồn tại A[6] =1 có số 
    
    lần xuất hiện là 3 nên ans[2] = 1.

 

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T;

    Những dòng tiếp theo mỗi dòng đưa vào một bộ test. 
    
    Mỗi bộ test gồm hai dòng, dòng đầu tiên đưa vào số n 
    
    là số các phần tử của mảng A[]; dòng tiếp theo đưa vào 
    
    n số của mảng A[]; các phần tử được viết cách nhau một vài khoảng trống.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ràng buộc:

    T, n, A[i] thỏa mãn ràng buộc: 1≤T≤100; 0≤n, A[i]≤106.

Ví dụ:

Input                       Output

1

7

1  1  2  3  4  2  1         -1 -1 1 2 2 1 -1

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
    unordered_map<int, int> mp;
    stack<int> st;
    for (int &x : a)
    {
        cin >> x;
        mp[x]++;
    }
    int b[n];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && mp[a[st.top()]] < mp[a[i]])
        {
            b[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        b[st.top()] = -1;
        st.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
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