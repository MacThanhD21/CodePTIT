
/*

    Cho một xâu s. Xâu F(s) được xác định bằng cách ghép xâu xâu s

    ban đầu với xâu s sau khi đã được quay vòng sang bên phải 1 kí tự

    (kí tự cuối cùng của s được chuyển lên đầu).

    Thực hiện liên tiếp các bước cộng xâu như trên với xâu mới thu được,

    ta có được xâu X.

    Nhiệm vụ của bạn là hãy xác định kí tự thứ N trong xâu X là kí tự nào?

Input:

    Dòng đầu ghi số bộ test T (T<10). Mỗi bộ test gồm một xâu s

    có độ dài không vượt quá 30 kí tự và số nguyên N (1 ≤ N ≤ 1018).

Output:

    Với mỗi bộ test ghi ra trên một dòng kí tự tìm được.

Ví dụ:

Input           Output

1

COW 8           C

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

string s;
ll k, n;

char find(ll k, ll n)
{
    if (k <= s.size())
        return s[k];
    if (k < n / 2)
        return find(k, n / 2);
    // if (k == n / 2)return find(k - 1, n / 2);
    if (k > n / 2)
        return find(k - n / 2 - 1, n / 2);
}

void solve()
{
    cin >> s >> k;
    --k;
    n = s.size();
    while (n < k)
        n *= 2; // chiều dài tối đa cần xét
    cout << find(k, n) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}