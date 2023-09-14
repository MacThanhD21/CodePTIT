

/*

    Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong

    K chỉ bao gồm các 0 hoặc 1 có nghĩa. Ví dụ số K = 1, 10, 101.

    Cho số tự nhiên N (N<263). Hãy cho biết có bao nhiêu số BDN nhỏ hơn N.

    Ví dụ N=100 ta có 4 số BDN bao gồm các số: 1, 10, 11, 100.

Input:

    Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;

    T dòng kế tiếp mỗi dòng ghi lại một bộ Test.

    Mỗi test là một số tự nhiên N.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input           Output

3

10              2

100             4

200             7

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve()
{
    queue<ll> Q;
    Q.push(1);
    vector<ll> v;
    while (Q.size())
    {
        ll val = Q.front();
        Q.pop();
        if (val >= 1e18)
        {
            break;
        }
        v.push_back(val);
        Q.push(val * 10);
        Q.push(val * 10 + 1);
    }

    int q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;

        int ans = lower_bound(v.begin(), v.end(), n) - v.begin();
        cout << ans << "\n";
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    solve();
}